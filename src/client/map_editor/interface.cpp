#include "interface.h"


Interface::Interface(std::string &file_name) : map(file_name) {
    this->file_name = "file_name";
}

void Interface::printMenu() {
    std::cout << "OPCIONES POSIBLES: " << std::endl;
    std::cout << "Bloque (1)" << std::endl;
    std::cout << "Puerta (2)" << std::endl;
    std::cout << "Boton (3)" << std::endl;
    std::cout << "Acido (4)" << std::endl;
    std::cout << "Roca (5)" << std::endl;
    std::cout << "Barrera de energia (6)" << std::endl;
    std::cout << "Emisor (7)" << std::endl;
    std::cout << "Exit (0)"<< std::endl;
    std::cout << "Elija una opcion: ";
}

std::string Interface:: createMap() {
    bool continue_adding_objects = true;
    while (continue_adding_objects) {
        this->printMenu();
        std::string option_choose;//podria hacer un swich o mejor un mapa
        std::cin >> option_choose;
        if (option_choose == "0") break;
        if (option_choose == "1") this->map.addBlock();
        if (option_choose == "2") this->map.addDoor();
        if (option_choose == "3") this->map.addButton();
        if (option_choose == "4") this->map.addAcid();
        if (option_choose == "5") this->map.addRock();
        if (option_choose == "6") this->map.addEnergyBarrier();
        if (option_choose == "7") this->map.addEmitter();        
        else std::cout << "Opicion invalida" << std::endl;
    }
    this->map.writeFile();
    return this->file_name;
}
