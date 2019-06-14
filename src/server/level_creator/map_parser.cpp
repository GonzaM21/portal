#include "map_parser.h"
#include "object.h"
#include "factory_objetcs.h"
#include <fstream>

MapParser :: MapParser(Model *model,std::string &json_file) : object_factory(model) {
    this->model = model;
    this->json_file = json_file;
    this->setMethods();
    this->setBlockMethods();
}

void MapParser :: createGate(nlohmann::json &object){
    ObjectGate* new_object = this->object_factory.createObjectGate((float)object.at("POS_X"),
    (float)object.at("POS_Y")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createButton(nlohmann::json &object){
    ObjectButton* new_object = this->object_factory.createObjectButton((float)object.at("POS_X"),
    (float)object.at("POS_Y"),object.at("DOOR_ID"),object.at("STATE")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createAcid(nlohmann::json &object){
    ObjectAcid* new_object = this->object_factory.createObjectAcid((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createPowerball(nlohmann::json &object){
    ObjectEnergyBall* new_object = this->object_factory.createObjectEnergyBall((float)object.at("POS_X"),
    (float)object.at("POS_Y")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createRock(nlohmann::json &object){
    ObjectRock* new_object = this->object_factory.createObjectRock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createEnergyBarrier(nlohmann::json &object){
    ObjectEnergyBarrier* new_object = this->object_factory.createObjectEnergyBarrier(
    (float)object.at("POS_X"),(float)object.at("POS_Y"),(float)object.at("HEIGHT")); 
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createBlock(nlohmann::json &object){
    (this->*(block_methods[object.at("TYPE_OPTIONAL")]))(object);
}

void MapParser :: createMetalBlock(nlohmann::json &object) {
    ObjectMetalBlock* new_object = this->object_factory.createObjectMetalBlock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createStoneBlock(nlohmann::json &object) {
    ObjectStoneBlock* new_object = this->object_factory.createObjectStoneBlock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    new_object->aggregate();
    delete new_object;
}

void MapParser :: createEmitter(nlohmann::json &object) {
    ObjectEmitter* new_object = this->object_factory.createObjectEmitter((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"),object.at("DIRECTION"),object.at("CHARGED"));
    new_object->aggregate();
    delete new_object;
}

void MapParser :: setBlockMethods() {
    this->block_methods[METAL_BLOCK] = &MapParser::createMetalBlock;
    this->block_methods[STONE_BLOCK] = &MapParser::createStoneBlock;
}

void MapParser :: setMethods() {
    this->methods[BLOCK_CODE] = &MapParser::createBlock;                   
    this->methods[GATE_CODE] = &MapParser::createGate;                     
    this->methods[BUTTON_CODE] = &MapParser::createButton;                   
    this->methods[ACID_CODE] = &MapParser::createAcid;                     
    this->methods[POWERBALL_CODE] = &MapParser::createPowerball;               
    this->methods[ROCK_CODE] = &MapParser::createRock;                     
    this->methods[ENERGY_BARRIER_CODE] = &MapParser::createEnergyBarrier;  
    this->methods[EMITTER_CODE] = &MapParser::createEmitter;
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
