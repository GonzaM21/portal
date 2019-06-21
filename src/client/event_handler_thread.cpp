#include <chrono>
#include <unistd.h>
#include "event_handler_thread.h"
#include "Event_handler.h"
#include "../common/Thread.h"

EventHandlerThread :: EventHandlerThread(ClientCommunicator *client_communicator,
    PositionConverter &converter) : eventHandler(client_communicator,converter) {
    this->continue_running = true;
}

void EventHandlerThread :: run() { //habria que validar que el unico evento valido al principio sea start sino te deja ya moverte y poner portales
    while (this->continue_running)  {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            this->eventHandler.handleEvent(event);
        }
        usleep(20000);
    }
}

void EventHandlerThread :: endExecution() {
    this->continue_running = false;
}
