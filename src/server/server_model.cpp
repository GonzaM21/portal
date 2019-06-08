#include "../server/server_model.h"
#include "../server/server_sender.h"
#include "level_creator/map_parser.h"
#define GROUND_WIDTH 200.f
#define GROUND_HEIGHT 1.f


Model :: Model(Sender *sender) { 
    GameLoop *game_loop = new GameLoop(&this->world,sender,&this->data_base);
    this->game_loop = game_loop;
    Ground ground(world, 0.f, -1.f, GROUND_WIDTH,GROUND_HEIGHT);
    this->data_base.setWidth((int)GROUND_WIDTH);
    this->data_base.setHeight((int)GROUND_HEIGHT);
}

void Model :: startGame() {
    try {
        game_loop->start();
    } catch (const std::exception &e) {
        std::cout << e.what();
    }
}

void Model :: endGame() {
    if (this->game_loop->gameLoopStarted()) {
        this->game_loop->endGameLoop();
        this->game_loop->join();
    }
    delete this->game_loop;
}

std::string Model :: getTime() {
    std::string current_time = this->game_loop->getTime();
    if (current_time == "NULL") return "The game has not started yet\n";
    return current_time; 
}

bool Model :: gameStarted() {
    return this->game_loop->gameLoopStarted();
}

World* Model :: getWorld() { //por ahora no lo uso
    return &this->world;
}

void Model :: makePlayerJump(std::string &player) {
    this->data_base.makePlayerJump(player);
}

void Model :: makePlayerMove(std::string &player,char &direction) {
    this->data_base.makePlayerMove(player,direction);
}

void Model :: addPlayer(std::string &player) {
    this->data_base.addPlayer(this->world,player);
}

void Model :: addRock(float x_pos, float y_pos, float radius) {
    this->data_base.addRock(this->world,x_pos,y_pos,radius);
}

void Model :: addAcid(float x_pos, float y_pos, float large) {
    this->data_base.addAcid(this->world,x_pos,y_pos,large);
}

void Model :: addEnergyBall(float x_pos, float y_pos) {
    this->data_base.addEnergyBall(this->world,x_pos,y_pos);
}

void Model :: addMetalBlock(float x_pos, float y_pos,float size) {
    this->data_base.addMetalBlock(this->world,x_pos,y_pos,size);      
}


std::string Model :: getJugadores() { //Puede llegar a servir mas adelante el comando creado por eso no borro
    std::cout << "allalalalalalalalalal\n";
    return "lalala";
}