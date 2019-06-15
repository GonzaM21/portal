#include "server_command_start.h"

CommandStart :: CommandStart(Model *model) {
    this->model = model;
}

void CommandStart :: execute() {
    this->model->startGame();
}
