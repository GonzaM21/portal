#ifndef COMMAND_ANTI_GRAVITY_H
#define COMMAND_ANTI_GRAVITY_H
#include <string>
#include "server_command.h"

/* 
* Clase para ejecutar el comando antigravedad para un 
* jugador en el modelo
*/

class CommandAntiGravity : public Command {
private:
    Model *model;
    std::string player;

public:
    CommandAntiGravity(Model *model,std::string &player);
    ~CommandAntiGravity() = default;
    void execute() override;
};

#endif