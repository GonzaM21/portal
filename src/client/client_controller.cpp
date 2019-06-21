#include "client_controller.h"

ClientController::ClientController() : 
    deserializer(&data_container,&scene_manager),
    converter(this->scene_manager.getModelFacade()) {
    this->communicator = new ClientCommunicator();
    this->handler = new EventHandlerThread(this->communicator,this->converter);
    this->renderer_thread = new Renderable(&this->scene_manager);
    this->continue_running = true;
}

void ClientController::endExecution() {
    this->continue_running = false;
}

ClientController::~ClientController() {
    this->handler->endExecution();
    this->handler->join();
    this->communicator->endExecution();
    this->communicator->join();
    this->renderer_thread->endExecution();
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

void ClientController::evaluateDataContainer() {
    this->renderer_thread->setMapReceived(this->data_container.getReceivedMap());
    if (this->data_container.getGameFinish()) this->endExecution();
}

void ClientController::mainLoop() {
    std::setlocale(LC_NUMERIC,"C");
    this->initializeCommunication();
    while (true) {
        std::string msg = this->communicator->popMessageReceived();
        if (!this->continue_running) break;
        this->deserializer.deserialize(msg);
        this->evaluateDataContainer();
    }
}

