#ifndef COMMAND_JUMP_H
#define COMMAND_JUMP_H
#include <string>
#include "server_command.h"


/* 
* Clase para llamar a la accion de salto
* para un jugador
*/


class CommandJump : public Command {
private:
    Model *model;
    std::string player;

public:
    CommandJump(Model *model,std::string &player);
    ~CommandJump() = default;
    void execute() override;
};

#endif