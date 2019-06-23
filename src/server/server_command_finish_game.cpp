#include <iostream>
#include "server_command_finish_game.h"
#define END_GAME 2


CommandFinishGame :: CommandFinishGame(Model *model) {
    this->model = model;
}

void CommandFinishGame :: execute() {
    this->model->endGame();
}
