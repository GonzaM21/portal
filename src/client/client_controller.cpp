#include "client_controller.h"

ClientController::ClientController() {
    this->communicator = new ClientCommunicator();
    this->continue_running = true;
}

void ClientController::endExecution() {
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
    if (!joiner.isValid()) return -1;
    return rv;
}

void ClientController::initializeCommunication() {
    this->renderer_thread->start();
    this->handler->start();
    this->communicator->start();    
}

void ClientController::evaluateDataContainer(DataContainer *data_container) {
    this->renderer_thread->setMapReceived(data_container->getReceivedMap());
    if (data_container->getGameFinish()) this->continue_running = false;
}

void ClientController::mainLoop() {
    try {
        SceneManager scene_manager;
        DataContainer data_container;
        ClientDeserializer deserializer(&data_container,&scene_manager);
        PositionConverter converter(scene_manager.getModelFacade());
        this->handler = new EventHandlerThread(this->communicator,converter);
        this->renderer_thread = new Renderable(&scene_manager);
        std::setlocale(LC_NUMERIC,"C");
        this->initializeCommunication();
        while (true) {
            std::string msg = this->communicator->popMessageReceived();
            if (!this->continue_running) break;
            deserializer.deserialize(msg);
            this->evaluateDataContainer(&data_container);
        }
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado" << std::endl;
    }
}

