#ifndef COMMAND_KILL_H
#define COMMAND_KILL_H
#include <string>
#include "server_command.h"

class CommandKill : public Command {
private:
    Model *model;
    std::string player;
    
public:
    explicit CommandKill(Model *model,std::string &voter);
    ~CommandKill() = default;
    void execute() override;
};

#endif