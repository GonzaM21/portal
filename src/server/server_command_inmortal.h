#ifndef COMMAND_INMORTAL_H
#define COMMAND_INMORTAL_H
#include <string>
#include "server_command.h"

/* 
* Clase para ejecutar el comando inmortal para un 
* jugador en el modelo
*/

class CommandInmortal : public Command {
private:
    Model *model;
    std::string player;

public:
    CommandInmortal(Model *model,std::string &player);
    ~CommandInmortal() = default;
    void execute() override;
};

#endif