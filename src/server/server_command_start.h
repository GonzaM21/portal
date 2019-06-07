#ifndef COMMAND_START_H
#define COMMAND_START_H
#include <string>
#include "../server/server_command.h"
#include "level_creator/map_parser.h"

class CommandStart : public Command {
private:
    Model *model;

public:
    explicit CommandStart(Model *model);
    ~CommandStart() = default;
    void execute() override;
};

#endif