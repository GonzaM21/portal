#ifndef MAP_PARSER_H
#define MAP_PARSER_H
#include <string>
#include <list>
#include "../server_model.h"
#include "../../common/json_parser/json.hpp"
#include "factory_objetcs.h"
#include "../../common/Constants.h"

class MapParser {
private:
    ObjectFactory object_factory;
    typedef void (MapParser::*map_method_t)(nlohmann::json&,std::list<Object*>&);
    std::unordered_map<int, map_method_t> methods; //functor
    std::unordered_map<int, map_method_t> block_methods;
    void setMethods();
    void setBlockMethods();
    void createBlock(nlohmann::json &object,std::list<Object*> &obj);
    void createGate(nlohmann::json &object,std::list<Object*> &obj);
    void createButton(nlohmann::json &object,std::list<Object*> &obj);
    void createAcid(nlohmann::json &object,std::list<Object*> &obj);
    void createPowerball(nlohmann::json &object,std::list<Object*> &obj);
    void createRock(nlohmann::json &object,std::list<Object*> &obj);
    void createEnergyBarrier(nlohmann::json &object,std::list<Object*> &obj);
    void createMetalBlock(nlohmann::json &object,std::list<Object*> &obj);
    void createStoneBlock(nlohmann::json &object,std::list<Object*> &obj);
    void createEmitter(nlohmann::json &object,std::list<Object*> &obj);
    void createCake(nlohmann::json &object,std::list<Object*> &obj);

public:
    MapParser(Model *model);
    ~MapParser() = default;
    std::list<Object*> addObjectsToModel(std::string &json_file);
};

#endif