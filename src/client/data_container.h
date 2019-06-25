#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H
#include <string>

class DataContainer {
private:
    bool error_message;
    std::string error;
    bool end_level;
    bool receive_map;
    bool end_game;
    bool waiting_next_level;

public:
    DataContainer();
    ~DataContainer() = default;

    //Setters
    void setReceivedMap(bool received_map);
    void setReceiveError(std::string &error_message);
    void setWaitingNextLevel(bool waiting_next_level);
    void setEndLevel(bool end_level);
    void setGameFinish();
    void setErrorMessage();

    //Getters
    bool getReceivedMap();
    bool getWaitingNextLevel();
    bool getGameFinish();
    bool getEndLevel();
    bool getReceiveError();
};

#endif