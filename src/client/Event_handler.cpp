#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/Event_handler.h"
#include "position_converter.h"

EventHandler::EventHandler(ClientCommunicator *client_communicator,
  PositionConverter &converter,LocalSceneLogic &local_scene_logic)
    : messageSender(client_communicator,converter),
    local_scene_logic(local_scene_logic) {
      this->send_data_locally = false;
} 

void EventHandler::handleEvent(SDL_Event &event) {
  switch (event.type) {
    case SDL_KEYDOWN: {
      SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
      handleKeyDown(keyEvent);
      break;
    }
    case SDL_KEYUP: {
      if (this->send_data_locally) {
        SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
        handleKeyUpLocal(keyEvent);
      } else {
        SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &)event;
        handleKeyUp(keyEvent);
      }
      break;
    }
    case SDL_QUIT: {
      messageSender.sendQuitGame();
      break;
    }
    case SDL_MOUSEBUTTONUP: {
      SDL_MouseButtonEvent &mouseEvent = (SDL_MouseButtonEvent &)event;
      handleMouseButtonUp(mouseEvent);
      break;
    }
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

void EventHandler::handleKeyUpLocal(SDL_KeyboardEvent& keyEvent) {
  std::string event("c");
  switch (keyEvent.keysym.sym)
  {
    case SDLK_q: {
      event = "q";
      this->local_scene_logic.setEvent(event);
      break;
    }
    default: {
      this->local_scene_logic.setEvent(event);
      break;
    }
  }
}

void EventHandler::handleKeyUp(SDL_KeyboardEvent& keyEvent) {
  switch (keyEvent.keysym.sym)
  {
    case SDLK_F11: {
      local_scene_logic.setFullScreen();
      break;
    }
    case SDLK_d:{
      messageSender.sendStop();
      break;
    }
    case SDLK_o:{
      messageSender.sendInmortalCheat();
      break;
    }
    case SDLK_v:{
      messageSender.sendAntiGravityCheat();
      break;
    }
    case SDLK_a: {
      messageSender.sendStop();
      break;
    }
    case SDLK_r: {
      messageSender.sendResetPortals();
      break;
    }
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
    case SDLK_m: {
      messageSender.sendQuitGame();
      break;
    }
    case SDLK_c: {
      local_scene_logic.record();
    }
    default:
      break;
  }
}

void EventHandler::handleMouseButtonUp(SDL_MouseButtonEvent& mouseEvent) {
  int x;
  int y;
  SDL_GetMouseState(&x,&y);
  switch (mouseEvent.button){
    case SDL_BUTTON_RIGHT:
      messageSender.sendPortal(x, y, 2);
      MusicBase::getInstance()->playMusic(PORTAL_SHOT_FX_ID,20);
      break;
    case SDL_BUTTON_LEFT:
      messageSender.sendPortal(x, y, 1);
          MusicBase::getInstance()->playMusic(PORTAL_SHOT_FX_ID,20);
      break;
  }
}

void EventHandler::setSendDataLocally(bool send_locally) {
  this->send_data_locally = send_locally;
}