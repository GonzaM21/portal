#ifndef MAP_PARSER_H
#define MAP_PARSER_H
#include <string>
#include "../server_model.h"
#include "json_parser/json.hpp"
#include "factory_objetcs.h"
#include "../../common/Constants.h"

class MapParser {
private:
    Model *model;
    std::string json_file;
    ObjectFactory object_factory;
    typedef void (MapParser::*map_method_t)(nlohmann::json&);
    std::unordered_map<int, map_method_t> methods;
    std::unordered_map<int, map_method_t> block_methods;
    void setMethods();
    void setBlockMethods();
    void createBlock(nlohmann::json &object);
    void createGate(nlohmann::json &object);
    void createButton(nlohmann::json &object);
    void createAcid(nlohmann::json &object);
    void createPowerball(nlohmann::json &object);
    void createRock(nlohmann::json &object);
    void createEnergyBarrier(nlohmann::json &object);
    void createMetalBlock(nlohmann::json &object);
    void createStoneBlock(nlohmann::json &object);

public:
    MapParser(Model *model,std::string &json_file);
    ~MapParser() = default;
    void addObjectsToModel();
};

#endif