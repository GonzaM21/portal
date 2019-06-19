#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "../common/Thread.h"
#include "../vista/ModelFacade.h"

class Renderable : public Thread {
private:
    ModelFacade *model_facade;
    bool continue_running;
    bool map_received;

public:
    Renderable(ModelFacade *model_facade);
    ~Renderable() = default;
    virtual void run() override;
    void setMapReceived(bool map_recevied);
    void endExecution();
};

#endif
