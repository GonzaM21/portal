#include "client_controller.h"

ClientController::ClientController() {
    this->communicator = new ClientCommunicator();
    this->continue_running = true;
    this->end_game =false;
    this->end_level =false;
    this->map_received =false;
    this->receive_error =false;
    this->waiting_next_level = false;
}

void ClientController::failureExit() {
    this->continue_running = false;
    this->end_game = true;
    this->communicator->endExecution();
    this->communicator->join();
    delete this->communicator;
}

void ClientController::endExecution() {
    this->end_game = true;
    this->continue_running = false;
    this->handler->endExecution();
    this->renderer_thread->endExecution();
    this->communicator->endExecution();
    this->handler->join();
    this->communicator->join();
    this->renderer_thread->join();
    delete this->communicator;
    delete this->handler;
    delete this->renderer_thread;
}


int ClientController::runInitialWindow(int argc, char *argv[]) {
    Joiner joiner;
    QtExecutor qt_window;
    int rv = qt_window.executeWindow(argc,argv,&joiner, this->communicator);
    if (!joiner.isValid()) return 1;
    return rv;
}

void ClientController::initializeCommunication() {
    this->renderer_thread->start();
    this->handler->start();
    this->communicator->start();    
}

//bool ClientController::localSceneAction(LocalSceneLogic &local_scene_logic) {
//    return false;
//}

void ClientController::updateLocalScene(LocalSceneLogic &local_scene_logic,
    SceneManager &scene_manager) {
    if (this->end_game) return;
    if (this->end_level && this->waiting_next_level) {
        this->handler->setSendDataLocally(true);
        /*if (scene_manager.getActualScreen() == END_LEVEL_SCREEN)*/ scene_manager.putNextLevelScene();
        return;
    } else if (!this->end_level && this->waiting_next_level) {
        this->handler->setSendDataLocally(false);
        /*if (scene_manager.getActualScreen()!= GAME_SCREEN)*/ scene_manager.putGameScene();
        return;
    }
}

void ClientController::evaluateLocalVariables(LocalSceneLogic &local_scene_logic,
    SceneManager &scene_manager) {
    if (this->end_game || this->receive_error) {
        this->continue_running = false;
        return;
    }    
    this->renderer_thread->setMapReceived(this->map_received);
    this->renderer_thread->setWaitingNextLevel(this->waiting_next_level);
    this->updateLocalScene(local_scene_logic,scene_manager);
}


void ClientController::updateControllerVariables(DataContainer *data_container) {
    this->end_game = data_container->getGameFinish();
    this->map_received = data_container->getReceivedMap();
    this->waiting_next_level = data_container->getWaitingNextLevel();
    this->end_level = data_container->getEndLevel();
    this->receive_error = data_container->getReceiveError();
} 

void ClientController::mainLoop() {
    try {
        SceneManager scene_manager;
        DataContainer data_container;
        LocalSceneLogic local_scene_logic(scene_manager);
        ClientDeserializer deserializer(&data_container,&scene_manager);
        PositionConverter converter(scene_manager.getModelFacade());
        this->handler = new EventHandlerThread(this->communicator,converter,local_scene_logic);
        this->renderer_thread = new Renderable(&scene_manager);
        std::setlocale(LC_NUMERIC,"C"); //Qt nos cambia el comportamiento de algunas funciones como atof y stof
        this->initializeCommunication();
        while (true) {
            std::string msg = this->communicator->popMessageReceived();
            //std::cout << this->end_game << " " << this->continue_running << std::endl;
            if (!this->continue_running || this->end_game) break;
            deserializer.deserialize(msg);
            this->updateControllerVariables(&data_container);
            this->evaluateLocalVariables(local_scene_logic,scene_manager);
        }
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado" << std::endl;
    }
}

