#include "server_client_acceptor.h"
#include <vector>

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
    std::vector<Communicator*> communicators;

    while (this->continue_running) {
        SocketConnect socket_c = socket->acceptSocket();
        this->current_id ++;
        if (!this->continue_running) {
            continue;
        }
        std::string id = std::to_string(this->current_id);
        communicators.push_back(new Communicator(std::move(socket_c),room_manager,&events,id));
        communicators.back()->start();
        for (unsigned int i = 0; i<communicators.size(); i++) {
            if (!communicators[i]->communicatorValid()) {
                communicators[i]->endExecution();
                communicators[i]->join();
                delete communicators[i];
            }        
        }        
    }

    room_manager->endExecution();

    for (unsigned int i = 0; i<communicators.size(); i++) {
        communicators[i]->endExecution();
        communicators[i]->join();
        delete communicators[i];        
    }

    room_manager->join();
    delete room_manager;
}
