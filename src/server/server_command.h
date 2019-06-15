#ifndef COMMAND_H
#define COMMAND_H
#include "server_model.h"

class Command {
public:
    Command() = default;
    ~Command() = default;
    virtual void execute() = 0;
};

#endif