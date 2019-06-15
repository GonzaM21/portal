#include "server_command_disconnected.h"

CommandDisconnected :: CommandDisconnected(std::map<std::string,bool>* players_connection
    ,std::string &player) {
    this->players_connection = players_connection;
    this->player = player;
}

void CommandDisconnected :: execute() {
    this->players_connection->at(this->player) = false;
}
