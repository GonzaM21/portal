#include "Protected_Data_Base.h"
#include <vector>

void ProtectedDataBase :: makePlayerJump(std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Jump();
}

void ProtectedDataBase :: makePlayerMove(std::string &player,char &direction) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Move(direction);
}

void ProtectedDataBase :: shootPortal(World &world,std::string &player,float x_destiny,
  float y_destiny,int portal_num) {
    Chell_Player *chell_player = this->players[player];
    b2Vec2 pos = chell_player->getPosition();
    Player_Portals *portals = this->player_portals[this->player_ids[player]-1];
    if (portal_num == 0) {
      portals->shotPortalIn(world,pos.x,pos.y,x_destiny,y_destiny);
    } else if (portal_num == 1) {
      portals->shotPortalOut(world,pos.x,pos.y,x_destiny,y_destiny);
    }
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

void ProtectedDataBase :: addPlayerPortals() {
    std::unique_lock<std::mutex> lck(m);
    size_t player_portals_id = this->player_portals.size();
    this->player_portals.insert({player_portals_id,new Player_Portals()});      
}

void ProtectedDataBase :: addPlayer(World &world,std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    float pos = this->players.size();
    this->players.insert({player,new Chell_Player(world,0.f,0.2f)});
    this->player_ids.insert({player,this->players.size()});
}

void ProtectedDataBase :: addEmitter(World &world,float x_pos, float y_pos, float size,std::string& direction, bool charged) {
    std::unique_lock<std::mutex> lck(m);
    size_t emitter_id = this->emitters.size();
    this->emitters.insert({emitter_id,new Energy_Emitters(world,x_pos,y_pos,size,direction,charged)});
}

void ProtectedDataBase :: addEnergyBarrier(World &world,float x_pos, float y_pos, float large) {
    std::unique_lock<std::mutex> lck(m);
    size_t emitter_id = this->barriers.size();
    this->barriers.insert({emitter_id,new Energy_Barrier(world,x_pos,y_pos,large)});
}

std::vector<std::string> ProtectedDataBase :: getIds() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<std::string> vect;
  for (auto const& element : this->players) {
    vect.push_back(element.first);
  }
  return std::move(vect);
}

std::vector<Chell_Player*> ProtectedDataBase :: getPlayers() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Chell_Player*> players;
  for (auto const& element : this->players) {
    players.push_back(element.second);
  }
  return std::move(players);
}

std::vector<Acid*> ProtectedDataBase :: getAcids() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Acid*> acids;
  for (auto const& element : this->acids) {
    acids.push_back(element.second);
  }
  return std::move(acids);
}

std::vector<Metal_Block*> ProtectedDataBase :: getMetalBlocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Metal_Block*> metal_blocks;
  for (auto const& element : this->metal_blocks) {
    metal_blocks.push_back(element.second);
  }
  return std::move(metal_blocks);
}

std::vector<Rock*> ProtectedDataBase :: getRocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Rock*> rocks;
  for (auto const& element : this->rocks) {
    rocks.push_back(element.second);
  }
  return std::move(rocks);
}

std::vector<Energy_Ball*> ProtectedDataBase :: getEnergyBalls() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Energy_Ball*> energy_balls;
  for (auto const& element : this->energy_balls) {
    energy_balls.push_back(element.second);
  }
  return std::move(energy_balls);
}

std::vector<Stone_Block*> ProtectedDataBase :: getStoneBlocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Stone_Block*> stone_blocks;
  for (auto const& element : this->stone_blocks) {
    stone_blocks.push_back(element.second);
  }
  return std::move(stone_blocks);
}

std::vector<Gate*> ProtectedDataBase :: getGates() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Gate*> gates;
  for (auto const& element : this->gates) {
    gates.push_back(element.second);
  }
  return std::move(gates);
}

std::vector<Bottom*> ProtectedDataBase :: getBottoms() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Bottom*> bottoms;
  for (auto const& element : this->bottoms) {
    bottoms.push_back(element.second);
  }
  return std::move(bottoms);
}

std::vector<Player_Portals*> ProtectedDataBase :: getPlayerPortals() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Player_Portals*> player_portals;
  for (auto const& element : this->player_portals) {
    player_portals.push_back(element.second);
  }
  return std::move(player_portals);
}

std::vector<Energy_Barrier*> ProtectedDataBase :: getBarriers() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Energy_Barrier*> barriers;
  for (auto const& element : this->barriers) {
    barriers.push_back(element.second);
  }
  return std::move(barriers);
}

std::vector<Energy_Emitters*> ProtectedDataBase :: getEmitters() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Energy_Emitters*> emitters;
  for (auto const& element : this->emitters) {
    emitters.push_back(element.second);
  }
  return std::move(emitters);
}

float ProtectedDataBase :: getWidth() {
  return GROUND_WIDTH;
}

float ProtectedDataBase :: getHeight() {
  return GROUND_HEIGHT;
}  
