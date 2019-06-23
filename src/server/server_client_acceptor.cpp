#include "server_client_acceptor.h"
#include <list>

ClientAcceptor :: ClientAcceptor(SocketAccept &socket) {
    this->continue_running = true;
    this->socket = &socket;
    this->current_id = 0;
}

void ClientAcceptor :: endExecution() {
    this->continue_running = false;
    this->socket->closeSocket();
}

void ClientAcceptor :: run() {
    ColaProtegida events;
    RoomManager *room_manager = new RoomManager(&events);
    room_manager->start();
    std::list<Communicator*> communicators;

    while (this->continue_running) {
        SocketConnect socket_c = socket->acceptSocket();
        this->current_id ++;
        if (!this->continue_running) {
            continue;
        } else {
            std::string id = std::to_string(this->current_id);
            communicators.push_back(new Communicator(std::move(socket_c),room_manager,&events,id));
            communicators.back()->start();      
        }
        for (auto i = communicators.begin(); i != communicators.end();) {
            if ((*i)->communicatorValid()) {
                ++i;
            } else {
                (*i)->join();
                delete (*i);
                i = communicators.erase(i);
            }
        }
        room_manager->eliminateInactivesRooms();
    }
    room_manager->closeRoomsSender();

    for (auto i = communicators.begin(); i!= communicators.end();) {
        (*i)->endExecution();
        (*i)->join();
        delete (*i);
        i = communicators.erase(i);
    }
    room_manager->eliminateInactivesRooms();                
    room_manager->endExecution();
    room_manager->join();
    delete room_manager;
}
