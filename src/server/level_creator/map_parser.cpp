#include "map_parser.h"
#include "object.h"
#include "factory_objetcs.h"
#include <fstream>

MapParser :: MapParser(Model *model) : object_factory(model) {
    this->setMethods();
    this->setBlockMethods();
}

void MapParser :: createGate(nlohmann::json &object,std::list<Object*> &obj){
    ObjectGate* new_object = this->object_factory.createObjectGate((float)object.at("POS_X"),
    (float)object.at("POS_Y")); 
    obj.push_back(new_object);
}

void MapParser :: createCake(nlohmann::json &object,std::list<Object*> &obj) {
    ObjectCake* new_object = this->object_factory.createObjectCake((float)object.at("POS_X"),
    (float)object.at("POS_Y")); 
    obj.push_back(new_object);
}

void MapParser :: createButton(nlohmann::json &object,std::list<Object*> &obj){
    ObjectButton* new_object = this->object_factory.createObjectButton((float)object.at("POS_X"),
    (float)object.at("POS_Y"),object.at("DOOR_ID"),object.at("STATE")); 
    obj.push_back(new_object);
}

void MapParser :: createAcid(nlohmann::json &object,std::list<Object*> &obj){
    ObjectAcid* new_object = this->object_factory.createObjectAcid((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH")); 
    obj.push_back(new_object);
}

void MapParser :: createPowerball(nlohmann::json &object,std::list<Object*> &obj){
    ObjectEnergyBall* new_object = this->object_factory.createObjectEnergyBall((float)object.at("POS_X"),
    (float)object.at("POS_Y")); 
    obj.push_back(new_object);
}

void MapParser :: createRock(nlohmann::json &object,std::list<Object*> &obj){
    ObjectRock* new_object = this->object_factory.createObjectRock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH")); 
    obj.push_back(new_object);
}

void MapParser :: createEnergyBarrier(nlohmann::json &object,std::list<Object*> &obj){
    ObjectEnergyBarrier* new_object = this->object_factory.createObjectEnergyBarrier(
    (float)object.at("POS_X"),(float)object.at("POS_Y"),(float)object.at("HEIGHT"),
    object.at("ORIENTATION")); 
    obj.push_back(new_object);
}

void MapParser :: createBlock(nlohmann::json &object,std::list<Object*> &obj){
    (this->*(block_methods[object.at("TYPE_OPTIONAL")]))(object,obj);
}

void MapParser :: createMetalBlock(nlohmann::json &object,std::list<Object*> &obj) {
    ObjectMetalBlock* new_object = this->object_factory.createObjectMetalBlock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    obj.push_back(new_object);
}

void MapParser :: createStoneBlock(nlohmann::json &object,std::list<Object*> &obj) {
    ObjectStoneBlock* new_object = this->object_factory.createObjectStoneBlock((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"));
    obj.push_back(new_object);
}

void MapParser ::createTriangularBlock(nlohmann::json &object,std::list<Object*> &obj) {
    ObjectTriangularBlock* new_object = this->object_factory.createObjectTriangularBlock
    ((float)object.at("POS_X"),(float)object.at("POS_Y"),(float)object.at("SIZE"),
    object.at("TYPE_OPTINAL")); 
    obj.push_back(new_object);
}

void MapParser :: createEmitter(nlohmann::json &object,std::list<Object*> &obj) {
    ObjectEmitter* new_object = this->object_factory.createObjectEmitter((float)object.at("POS_X"),
    (float)object.at("POS_Y"),(float)object.at("WIDTH"),object.at("DIRECTION"),object.at("CHARGED"));
    obj.push_back(new_object);
}

void MapParser :: setBlockMethods() {
    this->block_methods[METAL_BLOCK] = &MapParser::createMetalBlock;
    this->block_methods[STONE_BLOCK] = &MapParser::createStoneBlock;
    this->block_methods[3] = &MapParser::createTriangularBlock;//PONER CODIGOS
    this->block_methods[4] = &MapParser::createTriangularBlock;
    this->block_methods[5] = &MapParser::createTriangularBlock;
    this->block_methods[6] = &MapParser::createTriangularBlock;
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
    this->methods[CAKE_CODE] = &MapParser::createCake;
}

std::list<Object*> MapParser :: addObjectsToModel(std::string &json_file) {
    std::list<Object*> obj;
    std::ifstream file(json_file);
    if (!file.is_open()) {
        std::cout << "Error: File not found" << std::endl; //podria lanzar excepcion
        return obj;
    }
    nlohmann::json j;
    file >> j;
    for (auto& element : j) {
        (this->*(methods[element.at("TYPE")]))(element,obj); //deberia usar lambda
    }
    return obj;
}
