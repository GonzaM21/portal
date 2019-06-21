#ifndef CLIENT_DESERIALIZER_H
#define CLIENT_DESERIALIZER_H
#define END_LEVEL_CODE "1"
#define END_GAME_CODE "2"
#define NEXT_LEVEL_CODE "3"
#define START_MAP_CODE "4"
#define END_MAP_CODE "5"
#define OBJECT_CODE "6"
#define MATES_CODE "7"
#define ERROR_CODE "8"
#include <vector>
#include <string>
#include "data_container.h"
#include "scene_manager.h"

/*  
*  ClientDeserializer: Es la clase encargada de tomar un mensaje
*  del servidor y transformarlo en una accion que deba realizar 
*  el cliente.
*/

class ClientDeserializer {
private:
    DataContainer *data_container;
    SceneManager *scene_manager;

    //Recibe como parametro un mensaje y un vector. Separa el mensaje
    //por coma insertando cada palabra en el vector 
    void splitMessage(std::string &message,std::vector<std::string> &args);

public:
    ClientDeserializer(DataContainer *data_container,SceneManager *scene_manager);
    ~ClientDeserializer() = default;

    //Recibe como parametro un mensaje y lo deserializa
    void deserialize(std::string &message);
};

#endif