#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client_communicator.h"
#include "Message_sender.h"

class EventHandler {
public:
  EventHandler(ClientCommunicator *client_communicator
    ,PositionConverter &converter);
  ~EventHandler() = default;
  void handleEvent(SDL_Event &event);
  void handleKeyDown(SDL_KeyboardEvent &keyEvent);
  void handleKeyUp(SDL_KeyboardEvent &keyEvent);
  void handleMouseButtonUp(SDL_MouseButtonEvent &mousseEvent);

private:
  bool running;
  MessageSender messageSender;
};

#endif
