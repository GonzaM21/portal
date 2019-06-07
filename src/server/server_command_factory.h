#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include "../server/server_model.h"
#include "../server/server_command.h"
#include "../server/server_command_mates.h"
#include "../server/server_command_join.h"
#include "../server/server_command_start.h"
#include "../server/server_command_move.h"
#include "../server/server_command_jump.h"
#include "level_creator/map_parser.h"

class CommandFactory {
private:
    Model *model;
    MapParser *map_parser;

public:
    CommandFactory(Model *model,MapParser *map_parser);
    ~CommandFactory() = default;
    CommandMates* createCommandMates();
    CommandJoin* createCommandJoin(std::string &player);
    CommandStart* createCommandStart();
    CommandJump* createCommandJump(std::string &player);
    CommandMove* createCommandMove(std::string &player,char &direction);
    //los demas comandos
};




#endif
