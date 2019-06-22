#include "map_saver.h"
#include <sstream>
#define BLOCK_ID "2"
#define DOOR_ID "3"
#define BUTTON_ID "4"
#define ACID_ID "5"
#define ROCK_ID "8"
#define ENERGY_BARRIER_ID "9"
#define ENERGY_EMITTER_ID "10"
#define CAKE_ID "11"
//lazyfoo
//tapar la ventana

MapSaver::MapSaver(std::string file_name) : file(file_name) {
    codes["Metal"] = 1;
    codes["Stone"] = 2;
    codes["Acid"] = 3;
    codes["Tria4"] = 4;
    codes["Tria5"] = 5;
    codes["Tria6"] = 6;
    codes["Tria7"] = 7;
    codes["Rock"] = 8;
    codes["BarrH"] = 9;
    codes["BarrV"] = 10;
    codes["EnerU"] = 11;
    codes["EnerR"] = 12;
    codes["EnerD"] = 13;
    codes["EnerL"] = 14;
    codes["RecvU"] = 15;
    codes["RecvR"] = 16;
    codes["RecvD"] = 17;
    codes["RecvL"] = 18;
    codes["Cake"] = 19;
}

void getPosition(std::string &pos_x,std::string &pos_y) {
    //std::cout << "Posicion en x: ";
    std::cin >> pos_x;
    //std::cout << "Posicion en y: ";
    std::cin >> pos_y;
}

void MapSaver::addBlock(std::string type_optional,std::string size,std::string pos_x,std::string pos_y)
{
    std::map<std::string,std::string> m;
    m["TYPE"] = BLOCK_ID;
    m["TYPE_OPTIONAL"] = type_optional;
    m["WIDTH"] = size;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addEnergyBarrier(std::string size, std::string pos_x, std::string pos_y, std::string orientation)
{
    std::map<std::string,std::string> m;
    m["TYPE"] = ENERGY_BARRIER_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["HEIGHT"] = size;
    m["ORIENTATION"] = orientation;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addAcid(std::string size, std::string pos_x, std::string pos_y){
    std::map<std::string,std::string> m;
    m["TYPE"] = ACID_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["WIDTH"] = size;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addDoor(std::string pos_x, std::string pos_y){
    std::map<std::string,std::string> m;
    m["TYPE"] = DOOR_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addButton(std::string pos_x, std::string pos_y, std::string door_number, std::string state) {
    std::map<std::string,std::string> m;
    m["TYPE"] = BUTTON_ID;
    m["DOOR_ID"] = door_number;
    m["STATE"] = state;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addCake(std::string pos_x, std::string pos_y){
    std::map<std::string,std::string> m;
    m["TYPE"] = CAKE_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    this->objects.push_back(new JsonNode(m));    
}

void MapSaver::addEmitter(std::string pos_x,std::string pos_y,std::string size,std::string direction,std::string charged) {
    std::map<std::string,std::string> m;
    m["TYPE"] = ENERGY_EMITTER_ID;
    m["POS_X"] = pos_x;
    m["POS_Y"] = pos_y;
    m["WIDTH"] = size;
    m["DIRECTION"] = direction;
    m["CHARGED"] = charged;
    this->objects.push_back(new JsonNode(m));
}

void MapSaver::addRock(std::string pos_x, std::string pos_y, std::string size) {
    std::map<std::string,std::string> m;
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

void MapSaver::addObject(std::string object) {
    //std::cout << object.c_str() << std::endl;
    std::vector<std::string> arguments;
    splitMessage(object,arguments);
    //std::cout << arguments[0].c_str() << std::endl;
    int code = codes[arguments[0]];
    //std::cout << code << std::endl;
    switch (code)
    {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
        addBlock(std::to_string(code), "1", arguments[1], arguments[2]);
        break;    
    case 3:
        addAcid("1",arguments[1], arguments[2]);
        break;
    case 8:
        addRock(arguments[1], arguments[2], "0.5"); 
        break;
    case 9:
    case 10:
        // addEnergyBarrier(arguments[1], arguments[2], "1 ",std::to_string(code % 9));
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        addEmitter(arguments[1],arguments[2],"1",std::to_string(code%10),"1");
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        addEmitter(arguments[1], arguments[2], "1", std::to_string(code % 14), "0");
        break;
    case 19:
        addCake(arguments[1],arguments[2]);
        break;
    default:
        break;
    }
}

void MapSaver::splitMessage(std::string& message, std::vector<std::string>& arguments){
    std::stringstream ss(message);
    std::string token;
    while (getline(ss, token, ','))
    {
        arguments.push_back(token);
    }
}

MapSaver::~MapSaver() {
    for (auto i = this->objects.begin(); i != this->objects.end();) {
        delete (*i);
        i = this->objects.erase(i);
    }
}