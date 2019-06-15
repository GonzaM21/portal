#include "server_sender.h"
#include <iostream>

Sender :: ~Sender() {
    for (std::map<std::string,ColaProtegida*>::iterator 
    it=this->colas.begin(); it!=this->colas.end(); ++it) {
        delete it->second;
    }     
}

void Sender :: endExecution() {
    for (std::map<std::string,ColaProtegida*>::iterator 
    it=this->colas.begin(); it!=this->colas.end(); ++it) {
        it->second->set_terminar_ejecucion();
    }     
}

void Sender :: addMessageToSend(std::string &message) {
    for (std::map<std::string,ColaProtegida*>::iterator 
    it=this->colas.begin(); it!=this->colas.end(); ++it) {
        it->second->push(message);
    } 
}

void Sender :: sendMessageTo(const std::string &player,std::string &message) {
    for (std::map<std::string,ColaProtegida*>::iterator 
    it=this->colas.begin(); it!=this->colas.end(); ++it) {
        if (it->first == player) {
            it->second->push(message);
    }
    }
}

std::string Sender :: getMessageFor(const std::string &name) {
    std::string message("NULL");
    for (std::map<std::string,ColaProtegida*>::iterator 
    it=this->colas.begin(); it!=this->colas.end(); ++it) {
        if (it->first == name) {
            message = it->second->pop();
        }
    }
    return message;
}

void Sender :: addPlayer(const std::string &name) {
    ColaProtegida* cola = new ColaProtegida();
    this->colas.insert({name,std::move(cola)});
}
