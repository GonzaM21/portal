#define SWAP_CODE "9"
#include "ModelFacade.h"
#include <stdlib.h>

ModelFacade::ModelFacade(Window &window) : model1(window), model2(window)
{
  renderable = &model1;
  setteable = &model2; 
  receivedInitialData = false;
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
  if (arguments.at(0) == "9" && arguments.size() == 1) {
    swap(); 
    return;
  } else if (arguments.at(0) == "5" && arguments.size() == 1) {
    endInitialData();
    return;
  }
  (this->*(methods[atoi(arguments[0].c_str())]))(arguments);
}

void ModelFacade::swap() {
  //if (renderable == &model1) {
  //  renderable = &model2;
  //  setteable = &model1;
  //} else {
  //  renderable = &model1;
  //  setteable = &model2;
  //}
}

void ModelFacade::setPlayer(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setPlayer(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
  if (!receivedInitialData) {
    renderable->setPlayer(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
  }
}

void ModelFacade::setPlayerId(std::vector<std::string> arguments)
{
  setteable->setPlayerId(atoi(arguments[1].c_str()));
  if (!receivedInitialData) {
    renderable->setPlayerId(atoi(arguments[1].c_str()));
  }
}

void ModelFacade::renderAll()
{
  setteable->renderAll();
}

void ModelFacade::setBlock(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setBlock(dest, atoi(arguments[1].c_str()));
  if (!receivedInitialData) {
    renderable->setBlock(dest, atoi(arguments[1].c_str()));
  }
}

void ModelFacade::setGate(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setGate(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
  if (!receivedInitialData) {
    renderable->setGate(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
  }
}

void ModelFacade::setCake(std::vector<std::string> arguments) {
  Rect dest(stof(arguments[1]), stof(arguments[2]), stof(arguments[3]), stof(arguments[4]));
  setteable->setCake(dest);
  if (!receivedInitialData) {
    renderable->setCake(dest);
  }
}

void ModelFacade::setButton(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setButton(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
  if (!receivedInitialData) {
    renderable->setButton(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
  }
}

void ModelFacade::setAcid(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[1]), stof(arguments[2]), stof(arguments[3]), stof(arguments[4]));
  setteable->setAcid(dest);
  if (!receivedInitialData) {
    renderable->setAcid(dest);
  }
}

void ModelFacade::setPortal(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setPortal(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()), atoi(arguments[8].c_str()));
  if (!receivedInitialData) {
    renderable->setPortal(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()), atoi(arguments[8].c_str()));
  }
}

void ModelFacade::setEnergyEmitter(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setEnergyEmitter(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
  if (!receivedInitialData) {
    renderable->setEnergyEmitter(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
  }
}

void ModelFacade::setPowerball(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[1]), stof(arguments[2]), stof(arguments[3]), stof(arguments[4]));
  setteable->setPowerball(dest, atoi(arguments[5].c_str()));
  if (!receivedInitialData) {
    renderable->setPowerball(dest, atoi(arguments[6].c_str()));
  }
}

void ModelFacade::setRock(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  setteable->setRock(dest, atoi(arguments[1].c_str()));
  if (!receivedInitialData) {
    renderable->setRock(dest, atoi(arguments[1].c_str()));
  }
}

Window* ModelFacade::getWindow() {
  return setteable->getWindow();
}

void ModelFacade::setEnergyBarrier(std::vector<std::string> arguments) {
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  setteable->setEnergyBarrier(dest, atof(arguments[1].c_str()));
  if (!receivedInitialData) {
    renderable->setEnergyBarrier(dest, atof(arguments[1].c_str()));
  }
}

void ModelFacade::convertToWorld(Rect &worldPostion, const Rect &virtualPostion) {
  setteable->convertToWorld(worldPostion,virtualPostion);
  if (!receivedInitialData) {
    renderable->convertToWorld(worldPostion,virtualPostion);
  }
}

void ModelFacade::setBackground() {
  setteable->setBackground();
  if (!receivedInitialData)
  {
    renderable->setBackground();
  }
}

void ModelFacade::resetModel() {
  model1.resetModel();
  model2.resetModel();
}

void ModelFacade::endInitialData()
{
  receivedInitialData = true;
}