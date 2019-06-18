#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include "server_room_game.h"
#include "server_room_manager.h"
#include "../common/common_socket_connect.h"
#define MAX_PLAYERS 4 //deberia preguntar cunado se crea la sala?

RoomManager :: RoomManager(ColaProtegida *events) {
    this->continue_running = true;
    this->events = events;
}

bool RoomManager :: idIsValid(const std::string &id) {
    while (true) {
        for (std::map<std::string,bool>::iterator 
        it=this->ids.begin(); it!=this->ids.end(); ++it) {
            if (id == it->first) {
                return it->second;
            }
        }
    }
}

void RoomManager :: endExecution() {
    this->continue_running = false;
    this->events->set_terminar_ejecucion();
    for (RoomGame* & room : this->rooms) {
        std::cout << room->getName() << std::endl;
        room->endExecution();
    }        
}

bool RoomManager :: roomExist(std::string &room_name) {
    for (RoomGame* & room : this->rooms) {
        if (room->getName() == room_name) {
            return true;
        }
    }
    return false;
}

bool RoomManager :: createRoom(std::string &name) {
    if (this->roomExist(name)) return false;
    this->rooms_name.push_back(name);
    RoomGame *room = new RoomGame(name,MAX_PLAYERS);
    this->rooms.push_back(room);
    this->rooms.back()->start();
    return true;
}

std::list<std::string> RoomManager::getRoomsName() {
    return this->rooms_name;
}

bool RoomManager :: addPlayerToRoom(std::string &room_name,std::string &player_name){
    for (RoomGame* & room : this->rooms) {
        if (room->getName() == room_name) {
            return room->addPlayer(player_name);
        }
    }
    return false;
}

RoomManager :: ~RoomManager() {
    for (RoomGame* & room : this->rooms) {
        std::cout << room->getName() << std::endl;
        room->endExecution();
        room->join(); 
        delete room;
    }        
}

RoomGame* RoomManager :: getCreatedRoom(std::string &room_name) {
    RoomGame *room_p = nullptr;
    while (!room_p) {
        for (RoomGame* & room : this->rooms) {
            if (room->getName() == room_name) {
                room_p = room;
            }
        }
    }             
    return room_p;
}

void RoomManager :: splitMessage(std::string &message,std::string &first_place,
  std::string &second_place,std::string &third_place,std::string &fourth_place){
    size_t pos = 0;
    int num = 0;
    std::string token;
    std::string delimiter = ",";
    while ((pos = message.find(delimiter)) != std::string::npos) {
        token = message.substr(0, pos);
        if (num == 0) first_place = token;
        if (num == 1) second_place = token;
        if (num == 2) third_place = token;
        message.erase(0, pos + delimiter.length());
        num++;
    }
    fourth_place = message; 
}

void RoomManager::eliminateInactivesRooms() {
    std::list<RoomGame*>::iterator it = this->rooms.begin();
    while (it != this->rooms.end()) {
        if (!((*it)->getRoomIsActive())) {
            (*it)->endExecution();
            (*it)->join(); 
            delete (*it);
            it = this->rooms.erase(it);
        } else {
            it++;
        }
    }
}

void RoomManager :: run() { //como hay un solo hilo desencolando eventos y es el que crea la salas no hace falta mutear aca
    while (this->continue_running) {
        std::string mode("None");
        std::string room_name("None");
        std::string player_name("None");
        std::string player_id("None");
        std::string message = this->events->pop();
        this->eliminateInactivesRooms();
        if (!this->continue_running) break;
        splitMessage(message,room_name,player_name,mode,player_id);

        if (mode == "new") {
            if (!this->createRoom(room_name)) this->ids.insert({player_id,false});
            this->addPlayerToRoom(room_name,player_name);
        }

        if (mode == "join") {
            if(!this->addPlayerToRoom(room_name,player_name)) this->ids.insert({player_id,false});
        }
        this->ids.insert({player_id,true});
    }
}
