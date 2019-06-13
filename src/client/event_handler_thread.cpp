#include <chrono>
#include <unistd.h>
#include "event_handler_thread.h"
#include "../common/Thread.h"
#include "client/Event_handler.h"

EventHandlerThread :: EventHandlerThread(MessageSender& sender ,
    ModelFacade *model_facade) : eventHandler(sender){
    this->continue_running = true;
    this->model_facade = model_facade;
}

void EventHandlerThread :: run() { //habria que validar que el unico evento valido al principio sea start sino te deja ya moverte y poner portales
    while (this->continue_running)  {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            eventHandler.handleEvent(event);
        }
        usleep(20000);
    }
}

void EventHandlerThread :: endExecution() {
    this->continue_running = false;
}
