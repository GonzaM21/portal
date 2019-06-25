#define SWAP_CODE "9"
#include "ModelController.h"
#include <stdlib.h>

ModelController::ModelController(Window &window) : model(window)
{
  methods[0] = &ModelController::setPlayerId;
  methods[1] = &ModelController::setPlayer;
  methods[2] = &ModelController::setBlock;
  methods[3] = &ModelController::setGate;
  methods[4] = &ModelController::setButton;
  methods[5] = &ModelController::setAcid;
  methods[6] = &ModelController::setPortal;
  methods[7] = &ModelController::setPowerball;
  methods[8] = &ModelController::setRock;
  methods[9] = &ModelController::setEnergyBarrier;
  methods[10] = &ModelController::setEnergyEmitter;
  methods[11] = &ModelController::setCake;
}

void ModelController::decodeMessages(std::vector<std::string> arguments)//esto habria que hacerlo en deserializer (interprete)
{
  std::unique_lock<std::mutex> lck(m);
  (this->*(methods[atoi(arguments[0].c_str())]))(arguments);
}

void ModelController::setPlayer(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setPlayer(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
}

void ModelController::setPlayerId(std::vector<std::string> arguments)
{
  model.setPlayerId(atoi(arguments[1].c_str()));
}

void ModelController::renderAll()
{
  std::unique_lock<std::mutex> lck(m);
  model.renderAll();
}

void ModelController::setBlock(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setBlock(dest, atoi(arguments[1].c_str()));
}

void ModelController::setGate(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setGate(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
}

void ModelController::setCake(std::vector<std::string> arguments) {
  Rect dest(stof(arguments[1]), stof(arguments[2]), stof(arguments[3]), stof(arguments[4]));
  model.setCake(dest);
}

void ModelController::setButton(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setButton(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()));
}

void ModelController::setAcid(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[1]), stof(arguments[2]), stof(arguments[3]), stof(arguments[4]));
  model.setAcid(dest);
}

void ModelController::setPortal(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setPortal(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()), atoi(arguments[8].c_str()));
}

void ModelController::setEnergyEmitter(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setEnergyEmitter(dest, atoi(arguments[1].c_str()), atoi(arguments[6].c_str()), atoi(arguments[7].c_str()));
}

void ModelController::setPowerball(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setPowerball(dest, atoi(arguments[1].c_str()),atoi(arguments[6].c_str()),atoi(arguments[7].c_str()));
}

void ModelController::setRock(std::vector<std::string> arguments)
{
  Rect dest(stof(arguments[2]), stof(arguments[3]), stof(arguments[4]), stof(arguments[5]));
  model.setRock(dest, atoi(arguments[1].c_str()));
}

Window* ModelController::getWindow() {
  return model.getWindow();
}

void ModelController::setEnergyBarrier(std::vector<std::string> arguments) {
  Rect dest(atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()));
  model.setEnergyBarrier(dest, atof(arguments[1].c_str()));
}

void ModelController::convertToWorld(Rect &worldPostion, const Rect &virtualPostion) {
  model.convertToWorld(worldPostion,virtualPostion);
}

void ModelController::setBackground() {
  model.setBackground();
}

void ModelController::resetModel() {
  model.resetModel();
}
