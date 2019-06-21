#include "Protected_Data_Base.h"
#include <vector>
#define EMPTY_VOTE ""

void ProtectedDataBase::setLevel(World &world) {
    for (int i = -GROUND_WIDTH/2.f; i<GROUND_WIDTH/2.f; i++ ) {
        this->addMetalBlock(world,i,-5,1);
    }
    for (int i= 1; i>-6; i--) {
        this->addMetalBlock(world,-GROUND_WIDTH/2.f, i,1);
        this->addMetalBlock(world,GROUND_WIDTH/2.f, i,1);
    }
}

void ProtectedDataBase::makePlayerMoveRock(std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->grabARock();
}

void ProtectedDataBase::makePlayerInmortal(std::string &player) {
  std::unique_lock<std::mutex> lck(m);
  this->players[player]->inmortalChell();
}

void ProtectedDataBase::makePlayerAntiGravity(std::string &player) {
  std::unique_lock<std::mutex> lck(m);
  this->players[player]->antiGravity();
}



void ProtectedDataBase :: makePlayerJump(std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Jump();
}

void ProtectedDataBase ::voteToKill(std::string &voter) {//ACA TENIA QUE BUSCARLO CON LA FUNCION QUE ESTA ABAJO, DEBO ACOMODAR ESTO EN MODEL,FACTORY_COMMAND,COMANDO_KILLL/VER SUICIDAR, Y PROTOCOLO
    std::unique_lock<std::mutex> lck(m);
    std::string player_to_kill = getPlayerToKill();
    if (!this->win_state) return;
    this->vote_to_kill[voter] = player_to_kill;
    this->checkPlayerToKill(player_to_kill); 
}

void ProtectedDataBase :: makePlayerMove(std::string &player,char &direction) {
    std::unique_lock<std::mutex> lck(m);
    this->players[player]->Move(direction);
}

void ProtectedDataBase :: shootPortal(World &world,std::string &player,float x_destiny,
  float y_destiny,int portal_num) {
    Chell_Player *chell_player = this->players[player];
    if (portal_num == 1) {
      chell_player->shotPortalIn(x_destiny,y_destiny);
    } else if (portal_num == 2) {
      chell_player->shotPortalOut(x_destiny,y_destiny);
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

void ProtectedDataBase :: addGate(World &world, float x_pos, float y_pos) {//empieza de 0
    std::unique_lock<std::mutex> lck(m);
    size_t gate_id = this->gates.size();
    this->gates.insert({gate_id,new Gate(world,x_pos,y_pos)});      
}

void ProtectedDataBase ::addCake(World &world, float x_pos, float y_pos) {
    std::unique_lock<std::mutex> lck(m);
    size_t cake_id = this->cakes.size();
    this->cakes.insert({cake_id,new Cake(world,x_pos,y_pos)});      
}

void ProtectedDataBase::addTriangularBlock(World &world, float x_pos,
  float y_pos, float size, int type) {
    std::unique_lock<std::mutex> lck(m);
    size_t triag_block_id = this->triangular_blocks.size();
    this->triangular_blocks.insert({triag_block_id,new Metal_Block(world,x_pos,y_pos,size,45+(type-1)*90)});
}


void ProtectedDataBase :: addButton(World &world, float x_pos, float y_pos,int door_id,int state_to_open_door) { //tendra la puerta a la que se asignara el boton
    std::unique_lock<std::mutex> lck(m);
    size_t button_id = this->buttons.size();
    Button *button = new Button(world,x_pos,y_pos);
    this->buttons.insert({button_id,button});
    std::vector<size_t> info_button;
    info_button.push_back(door_id);
    info_button.push_back(state_to_open_door);
    this->pending_buttons.insert({button,std::move(info_button)});
}

void ProtectedDataBase :: addButtonToDoor() {
    for (auto button : this->pending_buttons) {
      int door_id = button.second[0]; 
      if (door_id >= this->gates.size()) continue;
      Gate* gate = this->gates[door_id];
      int state_to_open_door = button.second[1];
      gate->addButton(button.first,state_to_open_door);
    }
}

void ProtectedDataBase :: addPlayer(World &world,std::string &player) {
    std::unique_lock<std::mutex> lck(m);
    float pos = this->players.size();
    this->players.insert({player,new Chell_Player(world,0.f,0.2f)});
    this->player_ids.insert({player,this->players.size()});
    this->vote_to_kill.insert({player,EMPTY_VOTE});
    this->player_reach_cake.insert({player,false});
}

void ProtectedDataBase :: addEmitter(World &world,float x_pos, float y_pos, float size,int direction, bool charged) {
    std::unique_lock<std::mutex> lck(m);
    size_t emitter_id = this->emitters.size();
    this->emitters.insert({emitter_id,new Energy_Emitters(world,x_pos,y_pos,size,direction,charged)});
}

void ProtectedDataBase :: addEnergyBarrier(World &world,float x_pos, float y_pos, float large
  , int orientation) {
    std::unique_lock<std::mutex> lck(m);
    size_t emitter_id = this->barriers.size();
    this->barriers.insert({emitter_id,new Energy_Barrier(world,x_pos,y_pos,large,orientation)});
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

std::vector<Cake*> ProtectedDataBase :: getCakes() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Cake*> cakes;
  for (auto const& element : this->cakes) {
    cakes.push_back(element.second);
  }
  return std::move(cakes);
}

std::vector<Button*> ProtectedDataBase :: getButtons() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Button*> buttons;
  for (auto const& element : this->buttons) {
    buttons.push_back(element.second);
  }
  return std::move(buttons);
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

std::vector<Metal_Block*> ProtectedDataBase :: getTriangularBlocks() {
  std::unique_lock<std::mutex> lck(m);
  std::vector<Metal_Block*> triangular_blocks;
  for (auto const& element : this->triangular_blocks) {
    triangular_blocks.push_back(element.second);
  }
  return std::move(triangular_blocks);
}

float ProtectedDataBase :: getWidth() {
  return GROUND_WIDTH;
}

float ProtectedDataBase :: getHeight() {
  return GROUND_HEIGHT;
}  

std::map<std::string,Chell_Player*> ProtectedDataBase::getPlayersMap() {
  return this->players;
}

bool ProtectedDataBase::getWinState() { 
  return this->win_state;
}

std::map<std::string,std::string> ProtectedDataBase::getVoteToKill() {
  return this->vote_to_kill;
}

void ProtectedDataBase::setWinState() {
    std::unique_lock<std::mutex> lck(m);
    if (this->win_state) return;
    int counter = 0;
    for (auto player : this->player_reach_cake) {
        Chell_Player* chell = this->players[player.first];
        player.second = chell->getStatus()==3;
        if (player.second) counter++;
    }
    if (counter==this->player_reach_cake.size()-1) this->win_state=true;
}

void ProtectedDataBase::setVotes(std::map<std::string, size_t> &votes) {//PRIVADO
    for (auto player : this->players)
      votes.insert({player.first,0});
}

void ProtectedDataBase::checkPlayerToKill(std::string &player_to_kill) {//PRIVADO
    size_t counter = 0;
    for (auto player: this->vote_to_kill) {
      if (player.first == player_to_kill) continue;
      if (player.second == player_to_kill) counter++;
    }
    if (counter == this->players.size()-1) this->killPlayer(player_to_kill);
}

std::string ProtectedDataBase::getPlayerToKill() {//PRIVADO
    for (auto player : this->player_reach_cake) 
      if (!player.second) return player.first;
}

void ProtectedDataBase::killPlayer(std::string &player_name) {
    if (!this->win_state) return;
    this->players[player_name]->die();
}

std::string ProtectedDataBase::getPlayersName() {
    std::unique_lock<std::mutex> lck(m);
    std::string players("");
    size_t pos = 1;
    for (auto player : this->players) {
      if (pos == this->players.size()) {
        players += player.first; 
      } else {
        players += player.first +",";
        pos++;
      }
    }
    return players;
}

ProtectedDataBase::~ProtectedDataBase() {
    this->resetDataBase();
}

void ProtectedDataBase::resetDataBase() {
    this->resetPlayers();
    this->resetAcids();
    this->resetRocks();
    this->resetEnergyBalls();
    this->resetMetalBlocks();
    this->resetStoneBlocks();
    this->resetGates();
    this->resetButtons();
    this->resetEnergyBarriers();
    this->resetEnergyEmitters();
}

void ProtectedDataBase::resetPlayers() {
    for (auto it = this->players.cbegin(); it != this->players.cend();) {
        delete it->second;
        it = this->players.erase(it); 
    }
    for (auto it= this->player_ids.cbegin(); it != this->player_ids.cend();) {
        it = this->player_ids.erase(it); 
    }
    for (auto it= this->vote_to_kill.cbegin(); it != this->vote_to_kill.cend();) {
        it = this->vote_to_kill.erase(it); 
    }
    for (auto it= this->player_reach_cake.cbegin(); it != this->player_reach_cake.cend();) {
        it = this->player_reach_cake.erase(it); 
    }  
}

void ProtectedDataBase::resetRocks() {
    for (auto it = this->rocks.cbegin(); it != this->rocks.cend();) {
        delete it->second;
        it = this->rocks.erase(it); 
    }  
}

void ProtectedDataBase::resetAcids() {
    for (auto it = this->acids.cbegin(); it != this->acids.cend();) {
        delete it->second;
        it = this->acids.erase(it); 
    } 
}

void ProtectedDataBase::resetEnergyBalls() {
    for (auto it = this->energy_balls.cbegin(); it != this->energy_balls.cend();) {
        delete it->second;
        it = this->energy_balls.erase(it); 
    } 
}

void ProtectedDataBase::resetMetalBlocks() {
    for (auto it = this->metal_blocks.cbegin(); it != this->metal_blocks.cend();) {
        delete it->second;
        it = this->metal_blocks.erase(it); 
    } 
}

void ProtectedDataBase::resetStoneBlocks() {
    for (auto it = this->stone_blocks.cbegin(); it != this->stone_blocks.cend();) {
        delete it->second;
        it = this->stone_blocks.erase(it); 
    } 
}

void ProtectedDataBase::resetGates() {
    for (auto it = this->gates.cbegin(); it != this->gates.cend();) {
        delete it->second;
        it = this->gates.erase(it); 
    } 
}

void ProtectedDataBase::resetButtons() {
    for (auto it = this->buttons.cbegin(); it != this->buttons.cend();) {
        delete it->second;
        it = this->buttons.erase(it); 
    } 
}

void ProtectedDataBase::resetEnergyBarriers() {
    for (auto it = this->barriers.cbegin(); it != this->barriers.cend();) {
        delete it->second;
        it = this->barriers.erase(it); 
    } 
}

void ProtectedDataBase::resetEnergyEmitters() {
    for (auto it = this->emitters.cbegin(); it != this->emitters.cend();) {
        delete it->second;
        it = this->emitters.erase(it); 
    } 
}


//NOTA: REVISAR CUANDO ESTE EL CAKE SI DEBO MUTEAR ALGO MAS