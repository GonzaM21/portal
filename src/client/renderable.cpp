#define FPS 80

#include <chrono>
#include "renderable.h"
#include "../common/Thread.h"

Renderable :: Renderable(SceneManager *scene_manager) {
    this->scene_manager = scene_manager;
    this->continue_running = true;
}

void Renderable::setMapReceived(bool map_received) {
    this->map_received = map_received;
}

void Renderable :: endExecution() {
    this->continue_running = false;
}

void Renderable :: run() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
        if (!this->map_received) continue;
        if (!this->continue_running) break; //puede haber race condition? que pasa si da true y despues justo muere el communicator
        this->scene_manager->renderAll();
    }
}
