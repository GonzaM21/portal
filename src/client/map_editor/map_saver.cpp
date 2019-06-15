#include "map_saver.h"
#define BLOCK_ID "2"
#define DOOR_ID "3"
#define BUTTON_ID "4"
#define ACID_ID "5"
#define ROCK_ID "8"
#define ENERGY_BARRIER_ID "9"
#define ENERGY_EMITTER_ID "10"

MapSaver::MapSaver(std::string &file_name) : file(file_name) {}

void getPosition(std::string &pos_x,std::string &pos_y) {
    std::cout << "Posicion en x: ";
    std::cin >> pos_x;
    std::cout << "Posicion en y: ";
    std::cin >> pos_y;
}

void MapSaver::addBlock() {
    std::map<std::string,std::string> m;
    std::string type_optional;
    std::string size;
    std::string pos_x;
    std::string pos_y;
    std::cout << "TIPOS DE BLOQUES: " << std::endl;
    std::cout << "Metal 1" << std::endl;
    std::cout << "Piedra 2" << std::endl;
    std::cout << "Elija tipo: ";
    std::cin >> type_optional;
    getPosition(pos_x,pos_y);
    std::cout << "Tamaño: ";
    std::cin >> size;
    m["TYPE"] = BLOCK_ID;
    m["TYPE_OPTIONAL"] = type_optional;
    m["WIDTH"] = size;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addEnergyBarrier() {
    std::string pos_x;
    std::string pos_y;
    std::string size;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    std::cout << "Altura: ";
    std::cin >> size;
    m["TYPE"] = ACID_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["HEIGHT"] = size;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addAcid() {
    std::string pos_x;
    std::string pos_y;
    std::string size;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    std::cout << "Largo: ";
    std::cin >> size;
    m["TYPE"] = ACID_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["WIDTH"] = size;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addDoor() {
    std::string pos_x;
    std::string pos_y;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    m["TYPE"] = DOOR_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addButton() {
    std::string pos_x;
    std::string pos_y;
    std::string door_number;
    std::string state;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    std::cout << "Puerta asociada: ";
    std::cin >> door_number;
    std::cout << "Abajo (0)\nArriba (1)\n";
    std::cout << "Estado del boton para que abra la puerta: ";
    std::cin >> state;
    m["TYPE"] = BUTTON_ID;
    m["DOOR_ID"] = door_number;
    m["STATE"] = state;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addEmitter() {
    std::string pos_x;
    std::string pos_y;
    std::string size;
    std::string direction;
    std::string charged;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    std::cout << "Tamaño: ";
    std::cin >> size;
    std::cout << "Derecha (0)\nIzquierda (1)\nArriba (2)\nAbajo (3)\n";
    std::cout << "Direccion: ";
    std::cin >> direction;
    std::cout << "Descargado (0)\nCargado (1)\n";
    std::cout << "Carga: ";
    std::cin >> charged; 
    m["TYPE"] = ENERGY_EMITTER_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["WIDTH"] = size;
    m["DIRECTION"] = direction;
    m["CHARGED"] = charged;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addRock() {
    std::string pos_x;
    std::string pos_y;
    std::string size;
    std::map<std::string,std::string> m;
    getPosition(pos_x,pos_y);
    std::cout << "Tamaño: ";
    std::cin >> size;
    m["TYPE"] = ROCK_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["WIDTH"] = size;
    this->objects.push_back(new JsonNode(m));
}   


void MapSaver::writeFile() {
    this->file << "{\n";
    size_t actual_object(0);
    for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
        std::string id = "\"OBJECTID" + std::to_string(actual_object)+"\" : ";
        this->file << id;
        actual_object++;
        if (actual_object == this->objects.size()) break;
        json* node = (*it)->getJsonNode(); 
        this->file << node->dump(4);
        this->file << ",\n";
    }
    this->file << this->objects.at(actual_object-1)->getJsonNode()->dump(4);
    this->file << "\n}";
}


MapSaver::~MapSaver() {
    for (auto i = this->objects.begin(); i != this->objects.end();) {
        delete (*i);
        i = this->objects.erase(i);
    }
}