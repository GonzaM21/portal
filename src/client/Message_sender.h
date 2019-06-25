#ifndef __MESSAGESENDER_H__
#define __MESSAGESENDER_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/client_communicator.h"
#include "position_converter.h"

class MessageSender {
public:
  MessageSender(ClientCommunicator *communicator,PositionConverter &converter);
  ~MessageSender() = default;
  void sendMoveRight();
  void sendMoveLeft();
  void sendJump();
  void sendPortal(const int &x, const int &y, const int &code);
  void sendResetPortals();
  void sendQuitGame();
  void sendStart();
  void sendStop();
  void sendKillPlayer();
  void sendSuicide();
  void sendMoveRock();
  void sendDown();
  void sendInmortalCheat();
  void sendAntiGravityCheat();

private: 
  bool running;
  ClientCommunicator *communicator;
  PositionConverter position_converter;
};

#endif
