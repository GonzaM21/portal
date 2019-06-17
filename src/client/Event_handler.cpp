#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/Event_handler.h"

EventHandler::EventHandler(MessageSender& sender) : messageSender(sender) {
} 

void EventHandler::handleEvent(SDL_Event &event) {
  switch (event.type) {
    case SDL_KEYDOWN: {
      SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
      handleKeyDown(keyEvent);
    }
    break;
    case SDL_KEYUP: {
      SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
      handleKeyUp(keyEvent);
    }
    break;
    case SDL_QUIT: {
      std::cout << "cerrando" << std::endl;
      messageSender.sendQuitGame();
    }
      break;
    case SDL_MOUSEBUTTONUP: {
      SDL_MouseButtonEvent &mouseEvent = (SDL_MouseButtonEvent &)event;
      handleMouseButtonUp(mouseEvent);
    }
      break;
    default:
      break;
  }
}

void EventHandler::handleKeyDown(SDL_KeyboardEvent& keyEvent){
  switch (keyEvent.keysym.sym) {
    case SDLK_d: {
      messageSender.sendMoveRight();
      break;
    }
    case SDLK_a: {
      messageSender.sendMoveLeft();
      break;
    }
    case SDLK_DOWN: {
      messageSender.sendStart();
      break;
    }
  }
}

void EventHandler::handleKeyUp(SDL_KeyboardEvent& keyEvent) {
  switch (keyEvent.keysym.sym)
  {
    case SDLK_F11: {
      messageSender.sendFullscreen();
    }
      break;
    case SDLK_d:{
      messageSender.sendStop();
    }
      break;
    case SDLK_a: {
      messageSender.sendStop();
    }
      break;
    case SDLK_r: {
      messageSender.sendResetPortals();
    }
      break;
    case SDLK_w: {
      messageSender.sendJump();
      break;
    }
    case SDLK_s: {
        messageSender.sendDown();
        break;
    }
    case SDLK_e: {
      messageSender.sendMoveRock();
      break;
    }
    case SDLK_1: {
      messageSender.sendKillPlayer();
      break;
    }
    case SDLK_2: {
      messageSender.sendSuicide();
      break;
    }
    case SDLK_q: {
      std::cout << "exit" << std::endl;
      messageSender.sendQuitGame();
    }
      break;
    default:
      break;
  }
}

void EventHandler::handleMouseButtonUp(SDL_MouseButtonEvent& mouseEvent) {
  int x;
  int y;
  SDL_GetMouseState(&x,
                    &y);
  std::cout << "clicked"
            << "x " << x << "y " << y << std::endl;
  // Window *window = this->->getWindow();
  // int width, height;
  // window->getSize(width, height);
  // std::string x_world = std::to_string((x - (width / 2)) / (width * 0.12));
  // std::string y_world = std::to_string((y - (height / 2)) / (height * 0.12));
  // std::cout << "x: " << x_world << "y: " << y_world << std::endl;
  // std::string msg = "p," + x_world + "," + y_world;
  switch (mouseEvent.button){
    case SDL_BUTTON_RIGHT:
      messageSender.sendPortal(x, y, 2);
      break;
    case SDL_BUTTON_LEFT:
      messageSender.sendPortal(x, y, 1);
      break;
  }
}