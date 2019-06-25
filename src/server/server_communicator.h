#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <thread>
#include <mutex> 
#include "../common/common_socket_connect.h"
#include "../common/common_protocol.h"
#include "../common/common_cola_protegida.h"
#include "../common/Thread.h"
#include "server_room_manager.h"
#include "server_room_game.h"

/* 
* Clase encargada de comunicarse con un cliente 
* durante su conexion
*/



class Communicator : public Thread {
    private:
        std::string id;
        RoomManager *room_manager;
        ColaProtegida *events;
        std::string player_name;
        Sender *room_sender;
        RoomGame *room; 
        Protocol protocol;
        std::thread thread_s;
        bool thread_s_runnning;
        bool continue_running;
        bool is_valid;

        //Recibe los datos iniciales del jugador indicando
        //si los mismos son validos para unirse a la partida
        bool setInitialData(std::string &game_room,
          std::string &player_name);

    public:
        Communicator(SocketConnect socket,RoomManager *room_manager,
          ColaProtegida *events,std::string id); 
        ~Communicator();
        virtual void run() override;

        //Envia mensajes al cliente
        void sendMessage();

        //Recibe mensajes del cliente
        void receiveMessage();

        //Setea las variables para finaliza la 
        //ejecucion del comunicador
        void endExecution();

        //Devuelve un booleano indicando si el
        //comunicador es valido
        bool communicatorValid();
};


#endif
