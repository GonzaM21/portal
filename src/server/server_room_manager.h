#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H
#include <string>
#include <list>
#include <map>
#include "server_room_game.h"
#include "../common/common_cola_protegida.h"
#include "../common/common_socket_connect.h"
#include <mutex>

class RoomManager : public Thread {
    private:
        std::mutex m;
        std::list<RoomGame*> rooms;
        std::list<RoomGame*> inactive_rooms;
        bool continue_running;
        ColaProtegida *events;
        void splitMessage(std::string &message,std::string &first_place,
        std::string &second_place,std::string &third_place,
        std::string &fourth_place);
        std::map<std::string,bool> ids;
        void closeInactiveRooms();

        //Recibe como parametro un nombre y crea una sala
        bool createRoom(std::string &name);

        //Agrega un nuevo jugador a la sala.
        //Pre: La sala existe.
        bool addPlayerToRoom(std::string &room_name,
          std::string &player_name);

        //Devuelve un booleano si existe o no una sala
        //con el nombre recibido por parametro.
        bool roomExist(std::string &name);

    public:
        RoomManager(ColaProtegida *events);
        ~RoomManager();

        //Settea el final de ejecucion de una instancia
        void endExecution();

        RoomGame *getCreatedRoom(std::string &room);

        bool idIsValid(const std::string &id);

        void closeRoomsSender();

        void closeRoomSender(std::string &room_name);

        virtual void run() override;

        void eliminateInactivesRooms();

        bool roomSenderIsClose(std::string &room_name);
};

#endif