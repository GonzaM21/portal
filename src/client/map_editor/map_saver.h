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

public:
    MapSaver(std::string &file_name);
    ~MapSaver();
    void addBlock();
    void addEnergyBarrier();
    void addAcid();
    void addDoor();
    void addButton();
    void addEmitter();
    void addRock();    
    void writeFile();
}; 

#endif