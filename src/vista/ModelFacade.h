#ifndef __MODELFECADE_H__
#define __MODELFECADE_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Camara.h"
#include "Rect.h"
#include "Player/Player.h"
#include "Blocks/BlockFactory.h"
#include "Acid/Acid.h"
#include "Gate/Gate.h"
#include "Button/Button.h"
#include "PowerBall/PowerBall.h"
#include "Portal/Portal.h"
#include "Rocks/Rock.h"
#include "Model.h"
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

class ModelFacade
{
public:
  ModelFacade();
  ~ModelFacade() = default;
  void decodeMessages(std::vector<std::string> arguments);
  void setBlock(std::vector<std::string> arguments);
  void setGate(std::vector<std::string> arguments);
  void setButton(std::vector<std::string> arguments);
  void setAcid(std::vector<std::string> arguments);
  void setPortal(std::vector<std::string> arguments);
  void setPowerball(std::vector<std::string> arguments);
  void setRock(std::vector<std::string> arguments);
  void setPlayer(std::vector<std::string> arguments);
  void renderAll(std::vector<std::string> arguments);
  void setPlayerId(std::vector<std::string> arguments);
  void setEnergyEmitter(std::vector<std::string> arguments);
  void setEnergyBarrier(std::vector<std::string> arguments);

private:
  Model model;
  typedef void (ModelFacade::*model_method_t)(std::vector<std::string>);
  std::unordered_map<int, model_method_t> methods;
};

#endif
