#define FPS 80

#include <chrono>
#include "renderable.h"
#include "../common/Thread.h"

Renderable :: Renderable(ModelFacade *model_facade) {
    this->model_facade = model_facade;
    this->continue_running = true;
}

void Renderable :: run() {
    std::vector<std::string> dummyVector;
    while (this->continue_running) {
        this->model_facade->renderAll(dummyVector);
        std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
    }
}

void Renderable :: endExecution() {
    this->continue_running = false;
}
