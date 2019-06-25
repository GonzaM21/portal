#include "Message_sender.h"
#include <string>

MessageSender::MessageSender(ClientCommunicator* communicator,
        PositionConverter &converter) 
        :communicator(communicator),position_converter(converter) {
}

void MessageSender::sendMoveRight() {
  communicator->addMessageToSend("d");
}

void MessageSender::sendMoveLeft() {
  communicator->addMessageToSend("a");
}

void MessageSender::sendJump() {
  communicator->addMessageToSend("w");
}

void MessageSender::sendPortal(const int &x, const int &y, const int &code) {
  std::vector<int> world_coords = this->position_converter.convertToWorld(x,y);
  communicator->addMessageToSend("p," + std::to_string(world_coords.at(0)) + "," + 
    std::to_string(world_coords.at(1)) + "," + std::to_string(code));
}

void MessageSender::sendResetPortals() {
  communicator->addMessageToSend("r");
}

void MessageSender::sendQuitGame() {
  communicator->addMessageToSend("m");
}

void MessageSender::sendStart(){
  if (!this->communicator->isRunnning())
    return;
  communicator->addMessageToSend("start");
}

void MessageSender::sendStop() {
  communicator->addMessageToSend("z");
}

void MessageSender::sendKillPlayer() {
  communicator->addMessageToSend("1");
}

void MessageSender::sendSuicide() {
  communicator->addMessageToSend("2");
}

void MessageSender::sendMoveRock() {
  communicator->addMessageToSend("e");
}

void MessageSender::sendDown() {
  communicator->addMessageToSend("s");
}

void MessageSender::sendInmortalCheat() {
  communicator->addMessageToSend("o");
}

void MessageSender::sendAntiGravityCheat() {
  communicator->addMessageToSend("v");
}

