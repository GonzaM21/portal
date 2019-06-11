#ifndef EVENT_HANDLER_MANAGER_H
#define EVENT_HANDLER_MANAGER_H

#include "../common/Thread.h"
#include "client_communicator.h"
#include "vista/ModelFacade.h"

class EventHandlerManager : public Thread {
private:
    bool continue_running;
    ClientCommunicator *communicator;
    ModelFacade *model_facade;

public:
    EventHandlerManager(ClientCommunicator *communicator,
      ModelFacade *model_facade);
    ~EventHandlerManager() = default;
    virtual void run() override;
    void endExecution();
};

#endif
