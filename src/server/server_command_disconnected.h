#ifndef COMMAND_DISCONNECTED_H
#define COMMAND_DISCONNECTED_H
#include <string>
#include "server_command.h"

/* 
* Clase para ejecutar el comando desconexion para un 
* jugador en el modelo
*/

class CommandDisconnected : public Command {
private:
    std::map<std::string,bool>* players_connection;
    std::string player;

public:
    CommandDisconnected(std::map<std::string,bool>* players_connection
       ,std::string &player);
    ~CommandDisconnected() = default;
    void execute() override;
};

#endif