#ifndef COMMAND_MOVE_H
#define COMMAND_MOVE_H
#include <string>
#include "server_command.h"

/* 
* Clase para que un jugador se mueva
*/


class CommandMove : public Command {
private:
    Model *model;
    std::string player;
    char direction;

public:
    explicit CommandMove(Model *model,std::string &player,char &direction);
    ~CommandMove() = default;
    void execute() override;
};

#endif