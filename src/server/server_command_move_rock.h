#ifndef COMMAND_MOVE_ROCK_H
#define COMMAND_MOVE_ROCK_H
#include <string>
#include "server_command.h"

/* 
* Clase para que un jugador realize la accion de levantar
* o dejar una roca. 
*/


class CommandMoveRock : public Command {
private:
    Model *model;
    std::string player;

public:
    CommandMoveRock(Model *model,std::string &player);
    ~CommandMoveRock() = default;
    void execute() override;
};

#endif