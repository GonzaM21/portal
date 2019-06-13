#include "Message_sender.h"

MessageSender::MessageSender(ClientCommunicator* communicator) : communicator(communicator) {}

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