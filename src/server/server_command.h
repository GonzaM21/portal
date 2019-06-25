#ifndef COMMAND_H
#define COMMAND_H
#include "server_model.h"

/* 
* Clase abstracta utilizada para crear comandos
*/


class Command {
public:
    Command() = default;
    virtual ~Command() {}
    virtual void execute() = 0;
};

#endif