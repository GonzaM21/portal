#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "../common/Thread.h"
#include "../vista/ModelFacade.h"
#include "client_communicator.h"

class Renderable : public Thread {
private:
    ModelFacade *model_facade;
    bool continue_running;
    bool map_received;
    ClientCommunicator *communicator;

public:
    Renderable(ModelFacade *model_facade,
       ClientCommunicator *communicator);
    ~Renderable() = default;
    virtual void run() override;
    void setMapReceived();
    void endExecution();
};

#endif
