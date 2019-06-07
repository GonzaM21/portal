#include <chrono>
#include "event_handler_manager.h"
#include "../common/Thread.h"

EventHandlerManager :: EventHandlerManager(ClientCommunicator *communicator) {
    this->continue_running = true;
    this->communicator = communicator;
}

void EventHandlerManager :: run() {
    while (this->continue_running)  {
        //Algo
    }
}

void EventHandlerManager :: endExecution() {
    this->continue_running = false;
}
