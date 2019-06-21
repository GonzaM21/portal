#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "../common/Thread.h"
#include "scene_manager.h"

class Renderable : public Thread {
private:
    SceneManager *scene_manager;
    bool continue_running;
    bool map_received;

public:
    Renderable(SceneManager *scene_manager);
    ~Renderable() = default;
    virtual void run() override;
    void setMapReceived(bool map_recevied);
    void endExecution();
};

#endif
