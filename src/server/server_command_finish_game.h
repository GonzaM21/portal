#ifndef COMMAND_FINISH_GAME_H
#define COMMAND_FINISH_GAME_H
#include <string>
#include "server_command.h"

class CommandFinishGame : public Command {
private:
    Model *model;

public:
    explicit CommandFinishGame(Model *model);
    ~CommandFinishGame() = default;
    void execute() override;
};

#endif