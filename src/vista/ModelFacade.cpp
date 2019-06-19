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
  methods[8] = &ModelFacade::setRock;
  methods[9] = &ModelFacade::setEnergyBarrier;
  methods[10] = &ModelFacade::setEnergyEmitter;
  methods[11] = &ModelFacade::setCake;
}

void ModelFacade::decodeMessages(std::vector<std::string> arguments)//esto habria que hacerlo en deserializer (interprete)
{
  (this->*(methods[atoi(arguments[0].c_str())]))(arguments);
}

void ModelFacade::setPlayer(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setPlayer(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
}

void ModelFacade::setPlayerId(std::vector<std::string> arguments)
{
  model.setPlayerId(atoi(arguments[1].c_str()));
}

void ModelFacade::renderAll()
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

void ModelFacade::setCake(std::vector<std::string> arguments) {
  Rect dest(atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()));
  model.setCake(dest);
}

void ModelFacade::setButton(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setButton(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
}

void ModelFacade::setAcid(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()));
  model.setAcid(dest);
}

void ModelFacade::setPortal(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setPortal(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()), atoi(arguments[8].c_str()));
}

void ModelFacade::setEnergyEmitter(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setEnergyEmitter(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
}

void ModelFacade::setPowerball(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()));
  model.setPowerball(dest, atoi(arguments[5].c_str()));
}

void ModelFacade::setRock(std::vector<std::string> arguments)
{
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setRock(dest, atoi(arguments[1].c_str()));
}

Window* ModelFacade::getWindow() {
  return this->model.getWindow();
}

void ModelFacade::setEnergyBarrier(std::vector<std::string> arguments) {
  std::cout << arguments.at(0) << std::endl;
  std::cout << arguments.at(1) << std::endl;
  std::cout << arguments.at(2) << std::endl;
  std::cout << arguments.at(3) << std::endl;
  std::cout << arguments.at(4) << std::endl;
  std::cout << "Sin terminar las barreras" << std::endl;
}

void ModelFacade::convertToWorld(Rect &worldPostion, const Rect &virtualPostion) {
  model.convertToWorld(worldPostion,virtualPostion);
}
