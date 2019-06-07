#include "ModelFacade.h"
#include <stdlib.h>

ModelFacade::ModelFacade()
{
  methods[0] = &ModelFacade::setPlayerId;
  methods[1] = &ModelFacade::setPlayer;
  methods[2] = &ModelFacade::setBlock;
  methods[3] = &ModelFacade::setGate;
  methods[4] = &ModelFacade::setButton;
  methods[5] = &ModelFacade::setAcid;
  methods[6] = &ModelFacade::setPortal;
  methods[7] = &ModelFacade::setPowerball;
  // methods[8] = &ModelFacade::setRock;
  // methods[9] = &ModelFacade::setEnergyBarrier;
  methods[10] = &ModelFacade::setEnergyEmitter;
}

void ModelFacade::decodeMessages(std::vector<std::string> arguments)
{
  (this->*(methods[atoi(arguments[0].c_str())]))(arguments);
}

void ModelFacade::setPlayer(std::vector<std::string> arguments)
{
  std::cout << "entra a setear player\n";  
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setPlayer(dest, atof(arguments[1].c_str()), 0, 0);
  std::cout << "setea player\n";
}

void ModelFacade::setPlayerId(std::vector<std::string> arguments)
{
  std::cout << "setea player id\n";
  model.setPlayerId(atoi(arguments[1].c_str()));
}

void ModelFacade::renderAll(std::vector<std::string> arguments)
{
  model.renderAll();
}

void ModelFacade::setBlock(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setBlock(dest, atoi(arguments[1].c_str()));
}

void ModelFacade::setGate(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setGate(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
}

void ModelFacade::setButton(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setButton(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
}

void ModelFacade::setAcid(std::vector<std::string> arguments)
{
  std::cout << "entra a set acid\n";
  Rect dest(atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()));
  model.setAcid(dest);
  std::cout << "sale de set acid\n";
}

void ModelFacade::setPortal(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setPortal(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()), atoi(arguments[8].c_str()));
}

void ModelFacade::setEnergyEmitter(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  // model.setEnergyEmitter(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
}

void ModelFacade::setPowerball(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()));
  model.setPowerball(dest, atoi(arguments[5].c_str()));
}