#ifndef COMMAND_MATES_H
#define COMMAND_MATES_H
#include <string>
#include "server_command.h"

class CommandMates : public Command {
private:
    Model *model;

public:
    explicit CommandMates(Model *model);
    ~CommandMates() = default;
    void execute() override;
};

#endif