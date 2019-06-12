#define FPS 80

#include <chrono>
#include "renderable.h"
#include "../common/Thread.h"

Renderable :: Renderable(ModelFacade *model_facade,
    ClientCommunicator *communicator) {
    this->model_facade = model_facade;
    this->continue_running = true;
    this->communicator = communicator;
}

void Renderable :: run() {
    while (this->continue_running) {
        if (!this->communicator->getReceivedMap()) continue;
        if (!this->communicator->isRunnning()) break; //puede haber race condition? que pasa si da true y despues justo muere el communicator
        this->model_facade->renderAll();
        std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
    }
}

void Renderable :: endExecution() {
    this->continue_running = false;
}
