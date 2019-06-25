#include "client_controller.h"

ClientController::ClientController() {
    this->communicator = new ClientCommunicator(this->data_container);
    this->continue_running = true;
    this->end_game =false;
    this->end_level =false;
    this->map_received =false;
    this->receive_error =false;
    this->waiting_next_level = false;
    this->change_level = false;
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

void ClientController::updateClientAction(LocalSceneLogic &local_scene_logic,
    SceneManager &scene_manager) {
    while (this->continue_running) {
        if (local_scene_logic.getNextLevel()) {
            this->communicator->addMessageToSend("c");
            return;
        } else if (local_scene_logic.getEndGame()) {
            this->communicator->addMessageToSend("q");
            this->continue_running = false;
            return;
        }
        usleep(20000); //Duermo un tiempo el hilo para que el cpu no este al palo
    }
}

void ClientController::updateLocalScene(LocalSceneLogic &local_scene_logic,
    SceneManager &scene_manager) {
    if (this->end_game) return;
    if (this->end_level && this->waiting_next_level) {
        this->handler->setSendDataLocally(true);
        scene_manager.putNextLevelScene();
        scene_manager.resetLevelStage();
        this->change_level = true;
        this->updateClientAction(local_scene_logic,scene_manager);
        return;
    } else if (!this->end_level && !this->waiting_next_level && this->change_level) {
        this->handler->setSendDataLocally(false);
        scene_manager.putGameScene();
        this->change_level = false;
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
        LocalSceneLogic local_scene_logic(scene_manager);
        ClientDeserializer deserializer(&data_container,&scene_manager);
        PositionConverter converter(scene_manager.getModelFacade());
        this->handler = new EventHandlerThread(this->communicator,converter,local_scene_logic);
        this->renderer_thread = new Renderable(&scene_manager);
        std::setlocale(LC_NUMERIC,"C"); //Qt nos cambia el comportamiento de algunas funciones como atof y stof
        this->initializeCommunication();
        while (this->continue_running) {
            std::string msg = this->communicator->popMessageReceived();
            if (!this->continue_running || this->end_game) break;
            deserializer.deserialize(msg);
            this->updateControllerVariables(&data_container);
            this->evaluateLocalVariables(local_scene_logic,scene_manager);
        }
        scene_manager.putEndGameScene();
        for (int i = 0; i<5;i++) {
            usleep(1000000);
        }
        scene_manager.stopRocording();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado" << std::endl;
    }
}

