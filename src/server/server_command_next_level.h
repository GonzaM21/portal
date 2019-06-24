#ifndef COMMAND_NEXT_LEVEL_H
#define COMMAND_NEXT_LEVEL_H
#include <string>
#include "server_command.h"
#include "server_level_manager.h"

class CommandNextLevel : public Command {
private:
    Model *model;
    LevelManager *level_manager;
    std::string player;
    int vote;

public:
    CommandNextLevel(Model *model,LevelManager *level_manager,
      std::string &player);
    ~CommandNextLevel() = default;
    void execute() override;
};

#endif