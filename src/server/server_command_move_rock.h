#ifndef COMMAND_MOVE_ROCK_H
#define COMMAND_MOVE_ROCK_H
#include <string>
#include "../server/server_command.h"

class CommandMoveRock : public Command {
private:
    Model *model;
    std::string player;

public:
    CommandMoveRock(Model *model,std::string &player);
    ~CommandMoveRock() = default;
    void execute() override;
};

#endif