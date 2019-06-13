#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/client_communicator.h"
#include "client/Message_sender.h"

class EventHandler {
public:
  EventHandler(MessageSender& sender);
  ~EventHandler() {};
  void handleEvent(SDL_Event &event);
  void handleKeyDown(SDL_KeyboardEvent &keyEvent);
  void handleKeyUp(SDL_KeyboardEvent &keyEvent);
  void handleMouseButtonUp(SDL_MouseButtonEvent &mousseEvent);

private:
  bool running;
  MessageSender messageSender;
};

#endif
