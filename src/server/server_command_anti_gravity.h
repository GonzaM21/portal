#ifndef COMMAND_ANTI_GRAVITY_H
#define COMMAND_ANTI_GRAVITY_H
#include <string>
#include "server_command.h"

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