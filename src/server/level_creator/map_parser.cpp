#include "map_parser.h"
#include "object.h"
#include "factory_objetcs.h"
#include <fstream>

MapParser :: MapParser(Model *model,std::string json_file) : object_factory(model) {
    this->model = model;
    this->json_file = json_file;
    this->setMethods();
    this->setRockMethods();
}

void MapParser :: createGate(nlohmann::json &object){
    //creo objeto
}

void MapParser :: createButton(nlohmann::json &object){
    //creo objeto
}

void MapParser :: createAcid(nlohmann::json &object){
    Object* new_object = this->object_factory.createObjectAcid((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createPowerball(nlohmann::json &object){
    //creo objeto
}

void MapParser :: createRock(nlohmann::json &object){
    //creo objeto
}

void MapParser :: createEnergyBarrier(nlohmann::json &object){
    //creo objeto
}

void MapParser :: createBlock(nlohmann::json &object){
    (this->*(rock_methods[object.at("TYPE_OPTIONAL")]))(object);
}

void MapParser :: createMetalBlock(nlohmann::json &object) {
    Object* new_object = this->object_factory.createObjectMetalBlock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createStoneBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: createShootBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: createLauchUpBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: createLauchRightBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: createLauchDownBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: createLauchLeftBlock(nlohmann::json &object) {
    //creo objeto
}

void MapParser :: setRockMethods() {
    this->rock_methods[METAL_BLOCK] = &MapParser::createMetalBlock;
    this->rock_methods[STONE_BLOCK] = &MapParser::createStoneBlock;
    this->rock_methods[SHOOT_BLOCK] = &MapParser::createShootBlock;
    this->rock_methods[LAUNCH_UP_BLOCK] = &MapParser::createLauchUpBlock;
    this->rock_methods[LAUNCH_RIGHT_BLOCK] = &MapParser::createLauchRightBlock;
    this->rock_methods[LAUNCH_DOWN_BLOCK] = &MapParser::createLauchDownBlock;
    this->rock_methods[LAUNCH_LEFT_BLOCK] = &MapParser::createLauchLeftBlock;
}

void MapParser :: setMethods() {
    this->methods[BLOCK_CODE] = &MapParser::createBlock;                   
    this->methods[GATE_CODE] = &MapParser::createGate;                     
    this->methods[BUTTON_CODE] = &MapParser::createButton;                   
    this->methods[ACID_CODE] = &MapParser::createAcid;                     
    this->methods[POWERBALL_CODE] = &MapParser::createPowerball;               
    this->methods[ROCK_CODE] = &MapParser::createRock;                     
    this->methods[ENERGY_BARRIER_CODE] = &MapParser::createEnergyBarrier;           
}

void MapParser :: addObjectsToModel() {
    std::ifstream file(this->json_file);
    if (!file.is_open()) {
        std::cout << "Error: File not found" << std::endl; //podria lanzar excepcion
        return;
    }
    nlohmann::json j;
    file >> j;
    for (auto& element : j) {
        (this->*(methods[element.at("TYPE")]))(element);//si no guardan numeros en el json vuela todo
    }
}




//

//void MapParser :: 


//for (int i=0; i<10; i++) {
//    Object* new_object = this->object_factory.createObjectMetalBlock((float)i,-1.0f,1);
//    new_object->aggregate();
//    delete new_object;
//}
//Object* new_object = this->object_factory.createObjectAcid(3.0f,-1.0f,1.0f);
//new_object->aggregate();
//delete new_object;