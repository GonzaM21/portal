#ifndef COMMAND_SUICIDE_H
#define COMMAND_SUICIDE_H
#include <string>
#include "server_command.h"

/* 
* Clase para que un jugador se suicide
*/


class CommandSuicide : public Command {
private:
    Model *model;
    std::string player;

public:
    explicit CommandSuicide(Model *model,std::string &player);
    ~CommandSuicide() = default;
    void execute() override;
};

#endif