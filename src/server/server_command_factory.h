#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include "server_model.h"
#include "server_command.h"
#include "server_command_mates.h"
#include "server_command_join.h"
#include "server_command_start.h"
#include "server_command_move.h"
#include "server_command_jump.h"
#include "server_command_shoot.h"
#include "server_command_move_rock.h"
#include "server_command_disconnected.h"
#include "server_command_kill.h"
#include "server_command_suicide.h"
#include "server_command_anti_gravity.h"
#include "server_command_inmortal.h"
#include "level_creator/map_parser.h"
#include "server_level_manager.h"
#include <map>

class CommandFactory {
private:
    Model *model;
    LevelManager *level_manager;
    std::map<std::string,bool>* players_connection;
public:
    CommandFactory(Model *model,LevelManager *level_manager,
      std::map<std::string,bool>* players_connection);
    ~CommandFactory() = default;
    CommandMates* createCommandMates();
    CommandJoin* createCommandJoin(std::string &player);
    CommandStart* createCommandStart();
    CommandJump* createCommandJump(std::string &player);
    CommandMove* createCommandMove(std::string &player,char &direction);
    CommandShoot* createCommandShoot(std::string &player,
      std::string &x_destiny,std::string &y_destiny,std::string &portal_num);
    CommandMoveRock* createCommandMoveRock(std::string &player);
    CommandDisconnected* createCommandDisconnected(std::string &player);
    CommandKill* createCommandKill(std::string &voter);
    CommandSuicide* createCommandSuicide(std::string &player);
    CommandInmortal* createCommandInmortal(std::string &player);
    CommandAntiGravity* createCommandAntiGravity(std::string &player);
};




#endif
