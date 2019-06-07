#include "../server/server_model.h"
#include "../server/server_sender.h"
#include "level_creator/map_parser.h"

Model :: Model(Sender *sender) { //si le paso una referencia aca que estaria pasando ?
    GameLoop *game_loop = new GameLoop(&this->world,sender,&this->players);
    this->game_loop = game_loop;
    Ground ground(world, 0.f, 0.f, 20.f,1.f);
}

Model :: ~Model() {
    //for (auto player : this->players) {
        //delete player.second;
    //}   
}

void Model :: startGame() {
    try {
        //aca ya seteo todos los objetos del mapa en el gameloop porque ya no se van a poder agregarnevos objetos (estaticos con los dinamicos como bolas y portales todavia tengo que ver)
        game_loop->setMetalBlocks(&this->metal_blocks);
        game_loop->setAcids(&this->acids);
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

void Model :: addPlayer(std::string &player) {
    float pos = this->players.size();
    this->players.insert({player,new Chell_Player(world,pos,-2.8f)});
}

std::string Model :: getJugadores() {
    std::string jugadores("################\nJugadores:\n");
    for (auto player : this->players) {
        jugadores += player.first + " \n";
    }
    jugadores += "################\n";
    return jugadores;
}

World* Model :: getWorld() { //por ahora no lo uso
    return &this->world;
}

void Model :: makePlayerJump(std::string &player) {
    this->players[player]->Chell_Jump();
}

void Model :: makePlayerMove(std::string player,char &direction) {
    this->players[player]->Chell_Move(direction);
}


void Model :: addRock(float x_pos, float y_pos, float radius) {
    std::string rock_id = std::to_string(this->rocks.size());
    this->rocks.insert({rock_id,new Rock(this->world,x_pos,y_pos,radius)});
}

void Model :: addAcid(float x_pos, float y_pos, float large) {
    std::string acid_id = std::to_string(this->acids.size());
    this->acids.insert({acid_id,new Acid(this->world,x_pos,y_pos,large)});
}

void Model :: addEnergyBall(float x_pos, float y_pos) {
    std::string energy_ball_id = std::to_string(this->energy_balls.size());
    this->energy_balls.insert({energy_ball_id,new Energy_Ball(this->world,x_pos,y_pos)});    
}

void Model :: addMetalBlock(float x_pos, float y_pos,float size) {
    std::string metal_block_id = std::to_string(this->metal_blocks.size());
    this->metal_blocks.insert({metal_block_id,new Metal_Block(this->world,x_pos,y_pos,size)});    
}