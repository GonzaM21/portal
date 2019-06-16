#ifndef __MESSAGESENDER_H__
#define __MESSAGESENDER_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/client_communicator.h"

class MessageSender {
public:
  MessageSender(ClientCommunicator *communicator, ModelFacade* modelFacade);
  ~MessageSender() {};
  void sendMoveRight();
  void sendMoveLeft();
  void sendJump();
  void sendPortal(const int &x, const int &y, const int &code);
  void sendResetPortals();
  void sendQuitGame();
  void sendStart();
  void sendStop();
  void sendFullscreen();
  void sendKillPlayer();
  void sendSuicide();
  void sendMoveRock();

private: 
  bool running;
  ClientCommunicator *communicator;
  ModelFacade* modelFacade;
};

#endif
