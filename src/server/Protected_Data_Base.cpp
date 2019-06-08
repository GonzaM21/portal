#include "Protected_Data_Base.h"
#include <vector>

void ProtectedDataBase :: makePlayerJump(std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Chell_Jump();
}

void ProtectedDataBase :: makePlayerMove(std::string player,char &direction) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Chell_Move(direction);
}

void ProtectedDataBase :: addRock(World &world,float x_pos, float y_pos, float radius) {
    std::unique_lock<std::mutex> lck(m);
    size_t rock_id = this->rocks.size();
    this->rocks.insert({rock_id,new Rock(world,x_pos,y_pos,radius)});
}

void ProtectedDataBase :: addAcid(World &world,float x_pos, float y_pos, float large) {
    std::unique_lock<std::mutex> lck(m);
    size_t acid_id = this->acids.size();
    this->acids.insert({acid_id,new Acid(world,x_pos,y_pos,large)});
}

void ProtectedDataBase :: addEnergyBall(World &world,float x_pos, float y_pos) {
    std::unique_lock<std::mutex> lck(m);
    size_t energy_ball_id = this->energy_balls.size();
    this->energy_balls.insert({energy_ball_id,new Energy_Ball(world,x_pos,y_pos)});  
}

void ProtectedDataBase :: addMetalBlock(World &world,float x_pos, float y_pos,float size) {
    std::unique_lock<std::mutex> lck(m);
    size_t metal_block_id = this->metal_blocks.size();
    this->metal_blocks.insert({metal_block_id,new Metal_Block(world,x_pos,y_pos,size)});    
}

void ProtectedDataBase :: addPlayer(World &world,std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    float pos = this->players.size();
    this->players.insert({player,new Chell_Player(world,pos,-2.8f)});
}

std::vector<std::string> ProtectedDataBase :: getIds() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<std::string> vect;
  for (auto const& element : this->players) {
    vect.push_back(element.first);
  }
  return vect;
}

std::vector<Chell_Player*> ProtectedDataBase :: getPlayers() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Chell_Player*> players;
  for (auto const& element : this->players) {
    players.push_back(element.second);
  }
  return players;
}

std::vector<Acid*> ProtectedDataBase :: getAcids() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Acid*> acids;
  for (auto const& element : this->acids) {
    acids.push_back(element.second);
  }
  return acids;
}

std::vector<Metal_Block*> ProtectedDataBase :: getMetalBlocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Metal_Block*> metal_blocks;
  for (auto const& element : this->metal_blocks) {
    metal_blocks.push_back(element.second);
  }
  return metal_blocks;
}