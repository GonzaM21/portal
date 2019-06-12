#include <chrono>
#include "event_handler_manager.h"
#include "../common/Thread.h"

EventHandlerManager :: EventHandlerManager(ClientCommunicator *communicator,
    ModelFacade *model_facade) {
    this->continue_running = true;
    this->communicator = communicator;
    this->model_facade = model_facade;
}

void EventHandlerManager :: run() { //habria que validar que el unico evento valido al principio sea start sino te deja ya moverte y poner portales
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
                case SDLK_DOWN:
                {
                    std::cout << "ABAJO" << std::endl;
                    if (!this->communicator->isRunnning()) break;
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
                    communicator->addMessageToSend("s");
                    break;
                }
                case SDLK_a:
                {
                    std::cout << "Izquierda" << std::endl;
                    communicator->addMessageToSend("s");
                    break;
                }
                case SDLK_r:
                {
                    std::cout << "Reset" << std::endl;
                    communicator->addMessageToSend("r");
                    break;
                }
                case SDLK_w:
                {
                    std::cout << "Arriba" << std::endl;
                    communicator->addMessageToSend("w");
                    break;
                }
                case SDLK_q:
                {
                    std::cout << "exit" << std::endl;
                    communicator->endExecution();
                    break;
                }
                case SDLK_p:
                {
                    std::cout << "portal_0" << std::endl;
                    communicator->addMessageToSend("p,1.5,0.5,1");
                    break;
                }
                case SDLK_o:
                {
                    std::cout << "portal_1" << std::endl;
                    communicator->addMessageToSend("p,-1.5,0.5,2");
                    break;
                }
                }
            }
            break;
            case SDL_QUIT:
            {
                std::cout << "cerrando" << std::endl;
                this->continue_running = false;
                communicator->endExecution();
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
                Window *window = this->model_facade->getWindow();
                int width,height;
                window->getSize(width,height);
                std::string x_world = std::to_string((x-(width/2))/(width*0.12));
                std::string y_world = std::to_string((y-(height/2))/(height*0.12));
                std::cout << "x: " << x_world << "y: " << y_world << std::endl;
                std::string msg = "p,"+x_world+","+y_world; 
                switch (mouseEvent.button)
                {
                case SDL_BUTTON_RIGHT : {
                    msg += ",2";
                    communicator->addMessageToSend(msg);
                    break;
                }
                case SDL_BUTTON_LEFT: {
                    msg += ",1";
                    communicator->addMessageToSend(msg);
                    break;
                }
                }
                break;
            }
            }
        }
    }
}

void EventHandlerManager :: endExecution() {
    this->continue_running = false;
}
