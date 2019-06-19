#include "client_deserializer.h"

#include <sstream>

ClientDeserializer::ClientDeserializer(ModelFacade *model_facade) 
    : client_controller(model_facade) {}

void ClientDeserializer::deserialize(std::string &message) {
    std::vector<std::string> arguments;
    this->splitMessage(message,arguments);
    if (arguments.at(0) == ERROR_CODE && arguments.size() == 2) {
        this->client_controller.setReceiveError(arguments.at(1));
        return;
    } else if (arguments.at(0) == END_LEVEL_CODE && arguments.size() == 1) {
        this->client_controller.setReceivedMap(true);
        return;
    } else if (arguments.at(0) == END_GAME_CODE && arguments.size() == 1) {
        this->client_controller.setGameFinish();
        return;
    } else if (arguments.at(0) == NEXT_LEVEL_CODE && arguments.size() == 1) {
         this->client_controller.setWaitingNextLevel(true);
    } else if (arguments.at(0) == START_MAP_CODE && arguments.size() == 1) {
         this->client_controller.setWaitingNextLevel(false);
    } else if (arguments.at(0) == END_MAP_CODE && arguments.size() == 1) {
        this->client_controller.setReceivedMap(true);
        return;
    } else if (arguments.at(0) == MATES_CODE && arguments.size() == 1) {
        arguments.erase(arguments.begin(),arguments.begin()+1);
        this->client_controller.setMates(arguments);
    } else {//ESTE DEFAULT NO ES EL MEJOR, DEBERIA SER UN SWITCH CASE QUIZAA EL MURO ESTE DE IF Y PONER OTRO DEFAULT
        this->client_controller.decodeObjectMessage(arguments);
    }
}

void ClientDeserializer::splitMessage(std::string &message,std::vector<std::string> &args) {
    std::stringstream ss(message);
    std::string token;
    while (getline(ss, token, ',')) {
        args.push_back(token);
    }
}

bool ClientDeserializer::getReceiveError() {
    return this->client_controller.getReceiveError();
}

std::vector<std::string> ClientDeserializer::getMates() {
    return this->client_controller.getMates();
}