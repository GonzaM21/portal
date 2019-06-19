#ifndef COMMAND_INMORTAL_H
#define COMMAND_INMORTAL_H
#include <string>
#include "server_command.h"

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