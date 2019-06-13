#ifndef EVENT_HANDLER_THREAD_H
#define EVENT_HANDLER_THREAD_H

#include "../common/Thread.h"
#include "client_communicator.h"
#include "vista/ModelFacade.h"

class EventHandlerThread : public Thread {
private:
    bool continue_running;
    ClientCommunicator *communicator;
    ModelFacade *model_facade;

public:
    EventHandlerThread(ClientCommunicator *communicator,
      ModelFacade *model_facade);
    ~EventHandlerThread() = default;
    virtual void run() override;
    void endExecution();
};

#endif
