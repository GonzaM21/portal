#ifndef MAP_SAVER_H
#define MAP_SAVER_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "../../common/json_parser/json.hpp"
#include "json_node.h"
 
class MapSaver {
private:
    std::ofstream file;
    std::vector<JsonNode*> objects;
    std::map<std::string, int> codes;
public: 
    MapSaver(std::string file_name);
    ~MapSaver();
    void addBlock(std::string type_optional, std::string size, std::string pos_x, std::string pos_y);
    void addEnergyBarrier(std::string size, std::string pos_x, std::string pos_y, std::string orientation);
    void addAcid(std::string size, std::string pos_x, std::string pos_y);
    void addDoor(std::string pos_x, std::string pos_y, std::string id);
    void addButton(std::string pos_x, std::string pos_y, std::string door_number, std::string state);
    void addEmitter(std::string pos_x, std::string pos_y, std::string size, std::string direction, std::string charged);
    void addRock(std::string size, std::string pos_x, std::string pos_y);
    void addCake(std::string pos_x, std::string pos_y);
    void writeFile();
    void splitMessage(std::string &message, std::vector<std::string> &args); 
    void addObject(std::string object);
}; 

#endif