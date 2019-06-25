#define FPS 1000/20

#include <chrono>
#include "renderable.h"
#include "../common/Thread.h"

Renderable :: Renderable(SceneManager *scene_manager) {
    this->scene_manager = scene_manager;
    this->continue_running = true;
    this->waiting_next_level = false;
    this->map_received = false;
}

void Renderable::setWaitingNextLevel(bool waiting_next_level) {
    this->waiting_next_level = waiting_next_level;
}

void Renderable::setMapReceived(bool map_received) {
    this->map_received = map_received;
}

void Renderable :: endExecution() {
    this->continue_running = false;
    this->waiting_next_level = true;
}

void Renderable :: run() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
        if (!this->map_received && !this->waiting_next_level) continue;
        if (!this->continue_running) break;
        this->scene_manager->renderAll();
    }
}
