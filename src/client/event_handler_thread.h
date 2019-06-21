#ifndef EVENT_HANDLER_THREAD_H
#define EVENT_HANDLER_THREAD_H

#include "../common/Thread.h"
#include "client_communicator.h"
#include "Event_handler.h"
#include "position_converter.h"

class EventHandlerThread : public Thread {
private:
    bool continue_running;
    EventHandler eventHandler;

public:
    EventHandlerThread(ClientCommunicator *client_communicator,
      PositionConverter &converter);
    ~EventHandlerThread() = default;
    virtual void run() override;
    void endExecution();
};

#endif
