#include "vista/Model.h"
#include "vista/TextureBase.h"

Model::Model() : window(800, 800), camara(window), ownPlayerId(-1)
{
  TextureBase::getInstance(this->window.getRenderer());
}

void Model::setBlock(Rect &dest, const int &code)
{
  this->blocks.push_back(BlockFactory::createBlock(window, code));
  this->blocks.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}
void Model::setPortal(Rect &dest, const int &id, const int &code, const int &direction, const int &state)
{
  if (state == 1)
  {
    //if (id <= portals.size())
    //  delete this->portals[id];
    this->portals[id] = new Portal(window, code, direction);
    this->portals[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
  }
}

void Model::setEnergyEmitter(Rect &dest, const int &id, const int &direction, const int &state)
{
  if (id > emitters.size())
  {
    this->emitters[id] = new Emitter(window, direction, state);
  }
  this->emitters[id]->setState(state);
  this->emitters[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

void Model::setGate(Rect &dest, const int &id, const int &state)
{
  if (id > gates.size())
  {
    this->gates[id] = new Gate(window, id);
  }
  this->gates[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
  this->gates[id]->setState(state);
}
void Model::setButton(Rect &dest, const int &id, const int &state)
{
  if (id > buttons.size())
  {
    this->buttons[id] = new Button(window, state);
  }
  this->buttons[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
  this->buttons[id]->setState(state);
}
void Model::setAcid(Rect &dest)
{
  this->acids.push_back(new Acid(window));
  this->acids.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}
void Model::setPowerball(Rect &dest, const int &state)
{
  this->powerballs.push_back(new PowerBall(window, state));
  this->powerballs.back()->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}
void Model::setRock(Rect &dest, const int &id)
{
  if (id > rocks.size())
  {
    this->rocks[id] = new Rock(window);
  }
  this->rocks[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}
void Model::setPlayer(Rect &dest, const int &id, const int &state, const int &direction)
{
  if (id > players.size())
  {
    this->players[id] = new Player(window, direction);
  }
  this->players[id]->setState(state, direction);
  this->players[id]->setDestWorld(dest.getX(), dest.getY(), dest.getWidth(), dest.getHeight());
}

std::list<Block *> Model::getBlocks()
{
  return blocks;
}
std::list<Acid *> Model::getAcids()
{
  return acids;
}
std::list<PowerBall *> Model::getpowerballs()
{
  return powerballs;
}
std::unordered_map<int, Player *> Model::getPlayers()
{
  return players;
}
std::map<int, Button *> Model::getButtons()
{
  return buttons;
}
std::map<int, Gate *> Model::getGates()
{
  return gates;
}

void Model::renderAll()
{
  if (ownPlayerId == -1)
    return;
  window.fill();
  camara.setWindow(players[ownPlayerId]->getDestWorld().getX(), players[ownPlayerId]->getDestWorld().getY(), players[ownPlayerId]->getDestWorld().getWidth(), players[ownPlayerId]->getDestWorld().getHeight());

  for (Block *block : blocks)
  {
    block->render(camara);
  }

  for (Acid *acid : acids)
  {
    acid->render(camara);
  }

  std::map<int, Rock *>::iterator rock_it;
  for (rock_it = rocks.begin(); rock_it != rocks.end(); rock_it++)
  {
    rock_it->second->render(camara);
  }

  for (PowerBall *powerball : powerballs)
  {
    powerball->render(camara);
  }

  std::map<int, Portal *>::iterator portal_it;
  for (portal_it = portals.begin(); portal_it != portals.end(); portal_it++)
  {
    portal_it->second->render(camara);
  }

  for (auto &gate : gates)
  {
    gate.second->render(camara);
  }

  for (auto &emitter : emitters)
  {
    emitter.second->render(camara);
  }

  std::map<int, Button *>::iterator button_it;
  for (button_it = buttons.begin(); button_it != buttons.end(); button_it++)
  {
    button_it->second->render(camara);
  }

  for (auto &player : players)
  {
    player.second->render(camara);
  }

  window.render();
}

Model::~Model()
{
  for (Block *block : blocks)
  {
    delete block;
  }

  for (Acid *acid : acids)
  {
    delete acid;
  }

  for (PowerBall *powerball : powerballs)
  {
    delete powerball;
  }

  for (auto rock : rocks)
  {
    delete rock.second;
  }

  std::map<int, Portal *>::iterator portal_it;
  for (portal_it = portals.begin(); portal_it != portals.end(); portal_it++)
  {
    delete portal_it->second;
  }

  std::map<int, Gate *>::iterator gate_it;
  for (gate_it = gates.begin(); gate_it != gates.end(); gate_it++)
  {
    delete gate_it->second;
  }

  std::map<int, Button *>::iterator button_it;
  for (button_it = buttons.begin(); button_it != buttons.end(); button_it++)
  {
    delete button_it->second;
  }

  for (auto player : players)
  {
    delete player.second;
  }
}

Window* Model::getWindow() {
  return &this->window;
}