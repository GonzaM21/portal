#include "client_deserializer.h"
#include <sstream>

ClientDeserializer::ClientDeserializer(ModelFacade *model_facade) {
    this->model_facade = model_facade;
    this->receive_error = false;
    this->received_map = false;
    this->waiting_next_level = false;
    this->game_finish = false;
    //this->in_a_level = false;
}

void ClientDeserializer::deserialize(std::string &message) {
    std::vector<std::string> arguments;
    this->splitMessage(message,arguments);
    if (arguments.at(0) == ERROR_CODE) {
        this->receive_error = true;
        std::cout << arguments.at(1);
        return;
    } else if (arguments.at(0) == END_LEVEL_CODE && arguments.size() == 1) {
        this->received_map = false;
        this->waiting_next_level = true;
        return;
    } else if (arguments.at(0) == END_GAME_CODE && arguments.size() == 1) {
        this->game_finish = true;
        return;
    } else if (arguments.at(0) == NEXT_LEVEL_CODE && arguments.size() == 1) {
         //creo que no hace falta ya que solo me interesa cunado me empiezan a enviar un nuevo mapa
    } else if (arguments.at(0) == START_MAP_CODE && arguments.size() == 1) {
         //creo que no hace falta ya que solo me interesa cunado termina de enviar un nuevo mapa
    } else if (arguments.at(0) == END_MAP_CODE && arguments.size() == 1) {
        this->received_map = true;
        return;
    } else if (arguments.at(0) == MATES_CODE && arguments.size() == 1) {
        this->getMates();
    } else {
        this->model_facade->decodeMessages(arguments);
    }
}

bool ClientDeserializer::getReceiveMap() {
    return this->received_map;
}

bool ClientDeserializer::getInLevel() {
    return this->in_a_level;
}

bool ClientDeserializer::getWaitingNextLevel() {
    return  this->waiting_next_level;
}

bool ClientDeserializer::getReceiveError() {
    return this->receive_error;
}

void ClientDeserializer::setMates(std::vector<std::string> args) {
    this->mates = args;
}

std::vector<std::string> ClientDeserializer::getMates() {
    //std::cout << "lleho" << std::endl;
    //std::string mates("mates"); 
    //this->protocol << mates;
    std::string message("asd,dfasdf,sadfsadf");
    //this->protocol >> message;
    std::vector<std::string> arguments;
    //std::cout << message << std::endl;
    this->splitMessage(message, arguments);
    return arguments;
}

void ClientDeserializer::splitMessage(std::string &message,std::vector<std::string> &args) {
    std::stringstream ss(message);
    std::string token;
    while (getline(ss, token, ',')) {
        args.push_back(token);
    }
}