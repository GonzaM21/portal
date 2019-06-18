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


class ClientDeserializer {
private:
    bool received_map;
    bool in_a_level;
    bool waiting_next_level;
    bool receive_error;
    bool game_finish;
    std::vector<std::string> mates; //creo que nisiquiera es thread safety
    ModelFacade *model_facade;
    void splitMessage(std::string &message,std::vector<std::string> &args);
    void receiveMap();
    void setMates(std::vector<std::string> args);
public:
    ClientDeserializer(ModelFacade *model_facade);
    ~ClientDeserializer() = default;
    void deserialize(std::string &message);
    bool getReceiveMap();
    bool getInLevel();
    bool getWaitingNextLevel();
    bool getReceiveError();
    std::vector<std::string> getMates();
};

#endif