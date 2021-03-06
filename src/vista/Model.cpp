#include "Model.h"
#include "TextureBase.h"

Model::Model(Window &window) : window(window), camara(window), ownPlayerId(-1) {
  TextureBase::getInstance(this->window.getRenderer());
}

void Model::setBlock(Rect &dest, const int &code) {
  this->blocks.push_back(BlockFactory::createBlock(window, code));
  this->blocks.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}
void Model::setPortal(Rect &dest, const int &id, const int &code, const int &direction, const int &state) {
  if (portals.find(id) == portals.end()) {
    this->portals[id] = new Portal(window, code, direction);
  }
  this->portals[id]->setDirection(direction); 
  this->portals[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setEnergyEmitter(Rect &dest, const int &id, const int &direction, const int &state) {
  if (emitters.find(id) == emitters.end()) {
    this->emitters[id] = new Emitter(window, direction, state);
  }
  this->emitters[id]->setState(state);
  this->emitters[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setGate(Rect &dest, const int &id, const int &state) {
  if (gates.find(id) == gates.end()) {
    this->gates[id] = new Gate(window, id);
  }
  this->gates[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
  this->gates[id]->setState(state);
}

void Model::setEnergyBarrier(Rect &dest, const int &direction) {
  this->barriers.push_back(new EnergyBarrier(window, direction));
  this->barriers.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setButton(Rect &dest, const int &id, const int &state) {
  if (buttons.find(id) == buttons.end()) {
    this->buttons[id] = new Button(window, state);
  }
  this->buttons[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
  this->buttons[id]->setState(state);
}

void Model::setAcid(Rect &dest) {
  this->acids.push_back(new Acid(window));
  this->acids.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setCake(Rect &dest) {
  this->cakes.push_back(new Cake(window));
  this->cakes.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());  
}

void Model::setPowerball(Rect &dest, const int &id, const int &direction, const int &state) {
  if (powerballs.find(id) == powerballs.end())
  {
    this->powerballs[id] = new PowerBall(window, direction);
  }
  this->powerballs[id]->setState(state, direction);
  this->powerballs[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setRock(Rect &dest, const int &id) {
  if (rocks.find(id) == rocks.end()) {
    this->rocks[id] = new Rock(window);
  }
  this->rocks[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setPlayer(Rect &dest, const int &id, const int &state, const int &direction) {
  if (players.find(id) == players.end()) {
    this->players[id] = new Player(window, direction,id);
  }
  this->players[id]->setState(state, direction);
  this->players[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::convertToWorld(Rect &worldPostion, const Rect &virtualPostion) {
  camara.convertToWorld(worldPostion, virtualPostion);
}

void Model::renderAll() {
  if (ownPlayerId == -1)
    return;
  camara.setCamara(players[ownPlayerId]->getDestWorld().getX(), players[ownPlayerId]->getDestWorld().getY());

  for (Block *block : blocks) {
    block->render(camara);
  }

  for (Acid *acid : acids) {
    acid->render(camara);
  }
  
  for (EnergyBarrier* barrier : barriers) {
    barrier->render(camara);
  }

  for (auto &rock : rocks) {
    rock.second->render(camara);
  }

  for (auto& powerball : powerballs) {
    powerball.second->render(camara);
  }

  for (auto& gate : gates) {
    gate.second->render(camara);
  }

  for (auto& emitter : emitters) {
    emitter.second->render(camara);
  }

  for (auto& button : buttons) {
    button.second->render(camara);
  }

  for (auto &portal : portals) {
    portal.second->render(camara);
  }

  for (auto &player : players) {
    player.second->render(camara);
  }

  for (Cake* cake : cakes) {
    cake->render(camara);
  }
}

Model::~Model() {
  this->resetModel();
  for (auto it = this->players.cbegin(); it != this->players.cend();) {
      delete it->second;
      it = this->players.erase(it); 
  } 
}

Window* Model::getWindow() {
  return &this->window;
}

void Model::setBackground() {
  this->window.setBackground(BACKGROUND_FILENAME);
}

void Model::resetModel() {
  for (auto it = this->blocks.cbegin(); it != this->blocks.cend();) {
      delete (*it);
      it = this->blocks.erase(it); 
  }
  for (auto it = this->cakes.cbegin(); it != this->cakes.cend();) {
      delete (*it);
      it = this->cakes.erase(it); 
  }
  for (auto it = this->acids.cbegin(); it != this->acids.cend();) {
      delete (*it);
      it = this->acids.erase(it); 
  }
  for (auto it = this->emitters.cbegin(); it != this->emitters.cend();) {
    delete it->second;
    it = this->emitters.erase(it);
  }
  for (auto it = this->powerballs.cbegin(); it != this->powerballs.cend();) {
      delete it->second;
      it = this->powerballs.erase(it); 
  }
  for (auto it = this->barriers.cbegin(); it != this->barriers.cend();) {
    delete (*it);
    it = this->barriers.erase(it);
  }
  for (auto it = this->rocks.cbegin(); it != this->rocks.cend();) {
      delete it->second;
      it = this->rocks.erase(it); 
  }
  for (auto it = this->portals.cbegin(); it != this->portals.cend();) {
      delete it->second;
      it = this->portals.erase(it); 
  }
  for (auto it = this->gates.cbegin(); it != this->gates.cend();) {
      delete it->second;
      it = this->gates.erase(it); 
  }
  for (auto it = this->buttons.cbegin(); it != this->buttons.cend();) {
      delete it->second;
      it = this->buttons.erase(it); 
  }
}