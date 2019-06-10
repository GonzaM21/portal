#include "../server/server_command_shoot.h"

CommandShoot :: CommandShoot(Model *model,std::string &player,
  std::string &x_destiny,std::string &y_destiny,std::string &portal_num) {
    this->model = model;
    this->player = player;
    std::string::size_type sz;
    this->portal_num = std::stof(portal_num,&sz);
    this->x_destiny = std::stof(x_destiny,&sz);
    this->y_destiny = std::stof(y_destiny,&sz);
}

void CommandShoot :: execute() {
    this->model->shootPortal(this->player,this->x_destiny,
      this->y_destiny,this->portal_num);
}
