#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "../common/Thread.h"
#include "../vista/ModelFacade.h"

class Renderable : public Thread {
private:
    ModelFacade *model_facade;
    bool continue_running;

public:
    Renderable(ModelFacade *model_facade);
    ~Renderable() = default;
    virtual void run() override;
    void endExecution();
};

#endif
