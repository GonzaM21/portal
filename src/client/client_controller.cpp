#include "client_controller.h"

ClientController::ClientController(ModelFacade *model_facade) {
    this->renderer_thread = new Renderable(model_facade);
    this->renderer_thread->start();
    this->model_facade = model_facade;
    this->receive_error = false;
    //this->received_map = false;
    this->mates.push_back("None");
    this->waiting_next_level = false;
    this->game_finish = false;
}

ClientController::~ClientController() {
    this->renderer_thread->endExecution();
    this->renderer_thread->join();
    delete this->renderer_thread;
}

void ClientController::setReceivedMap(bool received_map) {
    //this->received_map = received_map;//creo que no lo necesito
    this->renderer_thread->setMapReceived(received_map);
}

void ClientController::setReceiveError(std::string &error_message) {
    this->receive_error = true;
    this->error_message = error_message;
}

void ClientController::setWaitingNextLevel(bool waiting_next_level) {
    this->waiting_next_level = waiting_next_level;
}

void ClientController::setGameFinish() {
    this->game_finish = true;
}

//bool ClientController::getReceivedMap() {
//    return this->received_map;
//}

bool ClientController::getWaitingNextLevel() {
    return this->waiting_next_level;
}

bool ClientController::getGameFinish() {
    return this->game_finish;
}

bool ClientController::getReceiveError() {
    return this->receive_error;
}

void ClientController::decodeObjectMessage(std::vector<std::string> &args) {
    this->model_facade->decodeMessages(args);
}

void ClientController::setMates(std::vector<std::string> &args) {
    this->mates = std::move(args);
}
std::vector<std::string> ClientController::getMates() {
    return this->mates;
}

