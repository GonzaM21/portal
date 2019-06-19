#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H
#include <vector>
#include <string>
#include "renderable.h"
#include "../vista/ModelFacade.h"

class ClientController {
private:
    Renderable *renderer_thread;
    ModelFacade *model_facade;
    bool receive_error;
    //bool received_map;
    bool waiting_next_level;
    bool game_finish;
    std::string error_message;
    std::vector<std::string> mates;

public: 
    ClientController(ModelFacade *model_facade);
    ~ClientController();
    void setReceivedMap(bool received_map);
    void setReceiveError(std::string &error_message);
    void setWaitingNextLevel(bool waiting_next_level);
    void setGameFinish();
    void setMates(std::vector<std::string> &args);
    //bool getReceivedMap();
    bool getWaitingNextLevel();
    bool getGameFinish();
    bool getReceiveError();
    void decodeObjectMessage(std::vector<std::string> &args);
    std::vector<std::string> getMates();
};

#endif