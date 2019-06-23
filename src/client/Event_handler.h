#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client_communicator.h"
#include "Message_sender.h"
#include "local_scene_logic.h"

class EventHandler {
public:
  EventHandler(ClientCommunicator *client_communicator
    ,PositionConverter &converter,LocalSceneLogic &local_scene_logic);
  ~EventHandler() = default;
  void handleEvent(SDL_Event &event);
  void handleKeyDown(SDL_KeyboardEvent &keyEvent);
  void handleKeyUp(SDL_KeyboardEvent &keyEvent);
  void handleMouseButtonUp(SDL_MouseButtonEvent &mousseEvent);
  void handleMouseButtonUpLocally(SDL_MouseButtonEvent &mousseEvent);
  void setSendDataLocally(bool send_locally);
  void handleKeyUpLocal(SDL_KeyboardEvent& keyEvent); 

private:
  bool running;
  MessageSender messageSender;
  bool send_data_locally;
  LocalSceneLogic &local_scene_logic;
};

#endif
