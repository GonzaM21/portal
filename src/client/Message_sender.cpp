#include "Message_sender.h"
#include <string>

MessageSender::MessageSender(ClientCommunicator* communicator, ModelFacade* modelFacade) 
        :communicator(communicator),
        modelFacade(modelFacade) 
        {}

void MessageSender::sendMoveRight(){
  communicator->addMessageToSend("d");
}

void MessageSender::sendMoveLeft()
{
  communicator->addMessageToSend("a");
}

void MessageSender::sendJump()
{
  communicator->addMessageToSend("w");
}

void MessageSender::sendPortal(const int &x, const int &y, const int &code) {
  Rect virtualPos(x,y,0,0);
  Rect worldPos(0,0,0,0);
  virtualPos.prfloat();
  modelFacade->convertToWorld(worldPos,virtualPos);
  worldPos.prfloat();
  communicator->addMessageToSend("p," + std::to_string(worldPos.getX()) + "," + std::to_string(worldPos.getY()) + "," + std::to_string(code));
}

void MessageSender::sendResetPortals() {
  communicator->addMessageToSend("r");
}

void MessageSender::sendQuitGame()
{
  communicator->addMessageToSend("q");
}

void MessageSender::sendStart(){
  if (!this->communicator->isRunnning())
    return;
  communicator->addMessageToSend("start");
}

void MessageSender::sendStop() {
  communicator->addMessageToSend("s");
}

void MessageSender::sendFullscreen() {
  communicator->addMessageToSend("fullscreen");
}