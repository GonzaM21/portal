#ifndef GAME_ROOM_H
#define GAME_ROOM_H
#include <string>
#include <list>
#include <queue>
#include <mutex>
#include <map>
#include "server_model.h"
#include "server_sender.h"
#include "../common/Thread.h"
#include "../common/common_cola_protegida.h"

class RoomGame : public Thread {
    private:
        std::mutex m;
        std::string name;
        ColaProtegida *messages;
        size_t size;
        Sender sender;
        std::map<std::string,bool> players;
        bool room_is_active;


        void sendMessageFrom(std::string &player,std::string &message);
        bool continue_running;
        void splitMessage(std::string &message,std::string &first_place,
        std::string &second_place);

        //Settea la variable room_is_active a true o false
        //dependiendo si hay o no jugadores conectados a la
        //sala
        void roomStillActive();

    public:
        RoomGame(std::string &name,size_t size);
        ~RoomGame();

        //Setea las variables para poder finalizar
        //la ejecucion de la sala correctamente.
        void endExecution();

        //Recibe como parametro un jugador y lo agrega a la sala
        bool addPlayer(std::string &name);

        //Envia un mensaje al resto de los jugadores que estan en
        //la sala del jugador que recibe por parametro
        //void sendMessageFrom(Player &player,std::string message);

        bool playerInRoom(const std::string &name);

        //Recibe como parametro un string y lo agrega a la 
        //cola protegida de la sala.
        void addMessageToSend(std::string &message);

        virtual void run() override;

        //Getters
        std::string getName();
        Sender* getSender();
        std::string getJugadores(); //HAY QUE BORRAR(creo) 
        bool getRoomIsActive();
};

#endif
