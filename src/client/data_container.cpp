#include "data_container.h"

DataContainer::DataContainer() {
    this->end_game =false;
    this->end_level =false;
    this->receive_map =false;
    this->error_message =false;
    this->waiting_next_level = false;
}


void DataContainer::setReceivedMap(bool received_map) {
    this->receive_map = received_map;
}

void DataContainer::setReceiveError(std::string &error_message) {
    this->error = error_message;
}

void DataContainer::setWaitingNextLevel(bool waiting_next_level) {
    this->waiting_next_level = waiting_next_level;
}

void DataContainer::setGameFinish() {
    this->end_game = true;
}

void DataContainer::setEndLevel(bool end_level) {
    this->end_level = end_level;
}


bool DataContainer::getEndLevel() {
    return this->end_level;
}

bool DataContainer::getReceivedMap() {
    return this->receive_map;
}

bool DataContainer::getWaitingNextLevel() {
    return this->waiting_next_level;
}

bool DataContainer::getGameFinish() {
    return this->end_game;
}

bool DataContainer::getReceiveError() {
    return this->error_message;
}
