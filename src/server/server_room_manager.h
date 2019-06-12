#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H
#include <string>
#include <list>
#include <map>
#include "../server/server_room_game.h"
#include "../common/common_cola_protegida.h"
#include "../common/common_socket_connect.h"
#include <mutex>

class RoomManager : public Thread {
    private:
        std::mutex m;
        std::list<RoomGame*> rooms;
        bool continue_running;
        ColaProtegida *events;
        void splitMessage(std::string &message,std::string &first_place,
        std::string &second_place,std::string &third_place,
        std::string &fourth_place);
        std::map<std::string,bool> ids;


    public:
        RoomManager(ColaProtegida *events);
        ~RoomManager();

        //Devuelve un booleano si existe o no una sala
        //con el nombre recibido por parametro.
        bool roomExist(std::string &name);

        //Recibe como parametro un nombre y crea una sala
        bool createRoom(std::string &name);

        //Agrega un nuevo jugador a la sala.
        //Pre: La sala existe.
        bool addPlayerToRoom(std::string &room_name,
          std::string &player_name);

        //Settea el final de ejecucion de una instancia
        void endExecution();

        void imprimirSalas(); //HAY QUE BORRAR 

        RoomGame *getCreatedRoom(std::string &room);

        bool idIsValid(const std::string &id);

        virtual void run() override;
};

#endif