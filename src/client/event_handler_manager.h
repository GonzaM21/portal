#ifndef EVENT_HANDLER_MANAGER_H
#define EVENT_HANDLER_MANAGER_H

#include "../common/Thread.h"
#include "client_communicator.h"

class EventHandlerManager : public Thread {
private:
    bool continue_running;
    ClientCommunicator *communicator;

public:
    EventHandlerManager(ClientCommunicator *communicator);
    ~EventHandlerManager() = default;
    virtual void run() override;
    void endExecution();
};

#endif
