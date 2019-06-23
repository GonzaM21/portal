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
        bool setInitialData(std::string &game_room,
          std::string &player_name);

    public:
        Communicator(SocketConnect socket,RoomManager *room_manager,
          ColaProtegida *events,std::string id); 
        ~Communicator();
        virtual void run() override;
        void sendMessage();
        void receiveMessage();
        void endExecution();
        bool communicatorValid();
        //void sendRooms();
        //void selectRoom(std::string &room);
};


#endif
