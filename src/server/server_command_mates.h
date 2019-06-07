#ifndef COMMAND_MATES_H
#define COMMAND_MATES_H
#include <string>
#include "../server/server_command.h"

class CommandMates : public Command {
private:
    Model *model;

public:
    explicit CommandMates(Model *model);
    ~CommandMates() = default;
    void execute() override;
    //CommandMates(const CommandMates&) = delete;
    //CommandMates& operator=(const CommandMates&) = delete;
    //CommandMates(CommandMates&& other);
    //CommandMates& operator=(CommandMates&& other);
};

#endif