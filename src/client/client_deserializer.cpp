#include "client_deserializer.h"
#include <sstream>

ClientDeserializer::ClientDeserializer(DataContainer *data_container
    ,SceneManager *scene_manager) {
        this->scene_manager = scene_manager;
        this->data_container = data_container;
}

void ClientDeserializer::deserialize(std::string &message) {
    if (message.size()< 10) std::cout << message << std::endl;
    std::vector<std::string> arguments;
    this->splitMessage(message,arguments);
    if (arguments.at(0) == ERROR_CODE && arguments.size() == 2) {
        this->data_container->setReceiveError(arguments.at(1));
        this->data_container->setGameFinish();
        return;
    } else if (arguments.at(0) == END_LEVEL_CODE && arguments.size() == 1) {
        this->data_container->setReceivedMap(false);
        this->data_container->setWaitingNextLevel(true);
        this->data_container->setEndLevel(true);
        return;
    } else if (arguments.at(0) == END_GAME_CODE && arguments.size() == 1) {
        this->data_container->setGameFinish();
        return;
    } else if (arguments.at(0) == NEXT_LEVEL_CODE && arguments.size() == 1) {
         this->data_container->setWaitingNextLevel(false);
    } else if (arguments.at(0) == START_MAP_CODE && arguments.size() == 1) {
         this->data_container->setEndLevel(false);
    } else if (arguments.at(0) == END_MAP_CODE && arguments.size() == 1) {
        this->data_container->setEndLevel(false);
        this->data_container->setWaitingNextLevel(false);
        this->data_container->setReceivedMap(true);
        this->scene_manager->decodeObjectMessage(arguments);
        return;
    } else if (arguments.at(0) == MATES_CODE && arguments.size() == 1) {
        //algo
    } else if (arguments.at(0) == "NULL"){
        std::cout << "Invalid message" << std::endl;
        this->data_container->setGameFinish();
        return;
    } else { 
        this->scene_manager->decodeObjectMessage(arguments);
    }
}

void ClientDeserializer::splitMessage(std::string &message,std::vector<std::string> &args) {
    std::stringstream ss(message);
    std::string token;
    while (getline(ss, token, ',')) {
        args.push_back(token);
    }
}
