#ifndef __MODEL_H__
#define __MODEL_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "vista/Window.h"
#include "vista/Camara.h"
#include "vista/Rect.h"
#include "vista/Player/Player.h"
#include "vista/Blocks/BlockFactory.h"
#include "vista/Acid/Acid.h"
#include "vista/Gate/Gate.h"
#include "vista/Button/Button.h"
#include "vista/PowerBall/PowerBall.h"
#include "vista/Portal/Portal.h"
#include "vista/Rocks/Rock.h"
#include "vista/Emitter/Emitter.h"
#include <list>
#include <map>
#include <unordered_map>

class Model
{
public:
  Model();
  ~Model();
  void setBlock(Rect &dest, const int &code);
  void setGate(Rect &dest, const int &id, const int &state);
  void setButton(Rect &dest, const int &id, const int &state);
  void setAcid(Rect &dest);
  void setPortal(Rect &dest, const int &id, const int &code, const int &direction, const int &state);
  void setPowerball(Rect &dest, const int &state);
  void setRock(Rect &dest, const int &id);
  void setEnergyEmitter(Rect &dest, const int &id, const int &direction, const int &state);
  void setPlayer(Rect &dest, const int &id, const int &state, const int &direction);
  std::list<Block *> getBlocks();
  std::list<Acid *> getAcids();
  std::list<PowerBall *> getpowerballs();
  std::unordered_map<int, Player *> getPlayers();
  std::map<int, Button *> getButtons();
  std::map<int, Gate *> getGates();
  void renderAll();
  void setPlayerId(int id) { ownPlayerId = id; }
  void fullscreen()
  {
    window.fullscreen();
  }

private:
  Window window;
  Camara camara;
  std::list<Block *> blocks;
  std::list<Acid *> acids;
  std::map<int, Rock *> rocks;
  std::map<int, Portal *> portals;
  std::list<PowerBall *> powerballs;
  std::unordered_map<int, Player *> players;
  std::unordered_map<int, Emitter *> emitters;
  std::map<int, Button *> buttons;
  std::map<int, Gate *> gates;
  int ownPlayerId;
};

#endif
