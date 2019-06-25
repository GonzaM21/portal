#ifndef COMMAND_SHOOT_H
#define COMMAND_SHOOT_H
#include <string>
#include "server_command.h"
#include "level_creator/map_parser.h"

/* 
* Clase para que un jugador dispare un portal
*/


class CommandShoot : public Command {
private:
    Model *model;
    std::string player;
    float x_destiny;
    float y_destiny;
    int portal_num;

public:
    explicit CommandShoot(Model *model,std::string &player,
      std::string & portal_num,std::string & x_destiny,std::string & y_destiny);
    ~CommandShoot() = default;
    void execute() override;
};

#endif