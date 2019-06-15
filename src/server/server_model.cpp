#include "server_model.h"
#include "server_sender.h"
#include "../common/Constants.h"
#include "level_creator/map_parser.h"



Model :: Model(Sender *sender) { 
    GameLoop *game_loop = new GameLoop(&this->world,sender,&this->data_base);
    this->game_loop = game_loop;
    ground = new Ground(world, 0.f, -1.f, GROUND_WIDTH,GROUND_HEIGHT);
}

Model :: ~Model(){
    delete ground;
}

void Model :: startGame() {
    if (this->gameStarted()) return;
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

void Model :: shootPortal(std::string &player,float x_destiny, float y_destiny,int portal_num) {
    this->data_base.shootPortal(this->world,player,x_destiny,y_destiny,portal_num);
}

void Model :: makePlayerMoveRock(std::string &player) {
    std::cout << "No esta hecho todavia el comando move rock en el modelo\n";
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

void Model :: addStoneBlock(float x_pos, float y_pos,float size) {
    this->data_base.addStoneBlock(this->world,x_pos,y_pos,size);
}

void Model :: addButton(float x_pos, float y_pos,int door_id,int state_to_open_door) {
    this->data_base.addButton(this->world,x_pos,y_pos,door_id,state_to_open_door);
}

void Model :: addGate(float x_pos, float y_pos) {
    this->data_base.addGate(this->world,x_pos,y_pos);
}

void Model::addEmitter(float x_pos, float y_pos, float size,int direction, bool charged) {
    this->data_base.addEmitter(this->world,x_pos,y_pos,size,direction,charged);
}

void Model::addEnergyBarrier(float x_pos, float y_pos, float large) {
    this->data_base.addEnergyBarrier(this->world,x_pos,y_pos,large);
}

std::string Model :: getJugadores() { //Puede llegar a servir mas adelante el comando creado por eso no borro
    std::cout << "allalalalalalalalalal\n";
    return "lalala";
}