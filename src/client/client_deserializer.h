#ifndef CLIENT_DESERIALIZER_H
#define CLIENT_DESERIALIZER_H
#define END_LEVEL_CODE "1"
#define END_GAME_CODE "2"
#define NEXT_LEVEL_CODE "3"
#define START_MAP_CODE "4"
#define END_MAP_CODE "5"
#define OBJECT_CODE "6"
#define MATES_CODE "7"
#define ERROR_CODE "8"
#include <vector>
#include <string>
#include "../vista/ModelFacade.h"
#include "client_controller.h"


class ClientDeserializer {
private:
    ClientController client_controller;

    void splitMessage(std::string &message,std::vector<std::string> &args);
    void receiveMap();
    void setMates(std::vector<std::string> args);
public:
    ClientDeserializer(ModelFacade *model_facade);
    ~ClientDeserializer() = default;
    void deserialize(std::string &message);
    //bool getReceiveMap();
    //bool getInLevel();
    //bool getWaitingNextLevel();
    //bool getReceiveError();
    bool getReceiveError(); //estos dos metodos deberian volar de aca
    std::vector<std::string> getMates();
};

#endif