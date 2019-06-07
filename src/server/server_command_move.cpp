#include "../server/server_command_move.h"

CommandMove :: CommandMove(Model *model,std::string &player,char &direction) {
    this->model = model;
    this->player = player;
    this->direction = direction;
}

void CommandMove :: execute() {
    //std::cout << "El player es: " << this->player << "con dir: " << this->direction << std::endl;
    this->model->makePlayerMove(this->player,this->direction);
}