#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include "map_saver.h" 
 
class Interface {
private:
    MapSaver map;
    std::string file_name;
    typedef void (Interface::*methods_t)();
    std::unordered_map<std::string, methods_t> methods;

public:
    Interface(std::string &file_name);
    ~Interface() = default;
    std::string createMap();
    void printMenu();
}; 

#endif