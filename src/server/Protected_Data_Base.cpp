#include "Protected_Data_Base.h"
#include <vector>

void ProtectedDataBase :: makePlayerJump(std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Jump();
}

void ProtectedDataBase :: makePlayerMove(std::string player,char &direction) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Move(direction);
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

void ProtectedDataBase :: addStoneBlock(World &world,float x_pos, float y_pos,float size) {
    std::unique_lock<std::mutex> lck(m);
    size_t stone_block_id = this->stone_blocks.size();
    this->stone_blocks.insert({stone_block_id,new Stone_Block(world,x_pos,y_pos,size)});      
}

void ProtectedDataBase :: addGate(World &world, float x_pos, float y_pos) {
    std::unique_lock<std::mutex> lck(m);
    size_t gate_id = this->gates.size();
    this->gates.insert({gate_id,new Gate(world,x_pos,y_pos)});      
}

void ProtectedDataBase :: addBottom(World &world, float x_pos, float y_pos) {
    std::unique_lock<std::mutex> lck(m);
    size_t bottom_id = this->bottoms.size();
    this->bottoms.insert({bottom_id,new Bottom(world,x_pos,y_pos)});      
}

//void ProtectedDataBase :: addPlayerPortals() {
//    std::unique_lock<std::mutex> lck(m);
//    size_t player_portals_id = this->player_portals.size();
//    this->player_portals.insert({player_portals_id,new Player_Portal()});      
//}

void ProtectedDataBase :: addPlayer(World &world,std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    float pos = this->players.size();
    this->players.insert({player,new Chell_Player(world,0.f,0.2f)});
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

std::vector<Rock*> ProtectedDataBase :: getRocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Rock*> rocks;
  for (auto const& element : this->rocks) {
    rocks.push_back(element.second);
  }
  return rocks;
}

std::vector<Energy_Ball*> ProtectedDataBase :: getEnergyBalls() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Energy_Ball*> energy_balls;
  for (auto const& element : this->energy_balls) {
    energy_balls.push_back(element.second);
  }
  return energy_balls;
}

std::vector<Stone_Block*> ProtectedDataBase :: getStoneBlocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Stone_Block*> stone_blocks;
  for (auto const& element : this->stone_blocks) {
    stone_blocks.push_back(element.second);
  }
  return stone_blocks;
}

std::vector<Gate*> ProtectedDataBase :: getGates() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Gate*> gates;
  for (auto const& element : this->gates) {
    gates.push_back(element.second);
  }
  return gates;
}

std::vector<Bottom*> ProtectedDataBase :: getBottoms() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Bottom*> bottoms;
  for (auto const& element : this->bottoms) {
    bottoms.push_back(element.second);
  }
  return bottoms;
}

//std::vector<Player_Portals*> ProtectedDataBase :: getPlayerPortals() {
//  std::unique_lock<std::mutex> lck(m);
//  std::vector<Player_Portals*> player_portals;
//  for (auto const& element : this->player_portals) {
//    player_portals.push_back(element.second);
//  }
//  return player_portals;
//}



float ProtectedDataBase :: getWidth() {
  return GROUND_WIDTH;
}

float ProtectedDataBase :: getHeight() {
  return GROUND_HEIGHT;
}  
