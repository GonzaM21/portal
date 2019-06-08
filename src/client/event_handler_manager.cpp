#include <chrono>
#include "event_handler_manager.h"
#include "../common/Thread.h"

EventHandlerManager :: EventHandlerManager(ClientCommunicator *communicator) {
    this->continue_running = true;
    this->communicator = communicator;
}

void EventHandlerManager :: run() {
    while (this->continue_running)  {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            {
                SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
                switch (keyEvent.keysym.sym)
                {
                case SDLK_d:
                {
                    communicator->addMessageToSend("d");
                    break;
                }
                case SDLK_a:
                {
                    std::cout << "Izquierda" << std::endl;
                    communicator->addMessageToSend("a");
                    break;
                }
                case SDLK_w:
                {
                    std::cout << "Arriba" << std::endl;
                    communicator->addMessageToSend("w");
                    break;
                }
                case SDLK_DOWN:
                {
                    std::cout << "ABAJO" << std::endl;
                    communicator->addMessageToSend("start");
                    break;
                }
                }
            }
            break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
                switch (keyEvent.keysym.sym)
                {
                case SDLK_F11:
                    communicator->addMessageToSend("fullscreen");
                    break;
                case SDLK_d:
                {
                    communicator->addMessageToSend("a");
                    break;
                }
                case SDLK_a:
                {
                    std::cout << "Izquierda" << std::endl;
                    communicator->addMessageToSend("d");
                    break;
                }
                case SDLK_r:
                {
                    std::cout << "Reset" << std::endl;
                    communicator->addMessageToSend("r");
                    break;
                }
                }
            }
            break;
            case SDL_QUIT:
            {
                std::cout << "cerrando" << std::endl;
                this->continue_running = false;
                communicator->addMessageToSend("q");
                break;
            }
            // case SDL_MOUSEMOTION:
            // {
            // 	SDL_MouseMotionEvent &mouseEvent = (SDL_MouseMotionEvent &)event;
            // 	int x;
            // 	int y;
            // 	SDL_GetMouseState(&x,
            // 										&y);
            // 	std::cout << "x " << x << "y " << y << std::endl;
            // 	break;
            // 	switch (mouseEvent.type)
            // 	{

            // 	default:
            // 		break;
            // 	}
            // }
            case SDL_MOUSEBUTTONUP:
            {
                SDL_MouseButtonEvent &mouseEvent = (SDL_MouseButtonEvent &)event;
                int x;
                int y;
                SDL_GetMouseState(&x,
                                  &y);
                std::cout << "clicked"
                          << "x " << x << "y " << y << std::endl;

                break;
            }
            }
        }
    }
}

void EventHandlerManager :: endExecution() {
    this->continue_running = false;
}
