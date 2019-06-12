#include "server_initializer.h"
#include <iostream>

Initializer::Initializer() {
    this->initialize_is_posible = true;
}


SocketAccept Initializer::initialiceSocketAccept(char *&port) {
    SocketAccept socket;
    if (!this->initialize_is_posible) return socket;
    if (!socket.addrinfo(port)) {
        std::cout << "Error: addrinfo fail" << std::endl;
        socket.setSocketToInvalid();
        return socket;
    }

    if (!socket.sktSocketAccept()) {
        std::cout << "Error: accept fail" << std::endl;
        socket.setSocketToInvalid();
        return socket;
    }

    if (!socket.sktOpciones()) {
        std::cout << "Error: setting options fail" << std::endl; 
        socket.setSocketToInvalid();
        return socket;		
    }

    if (!socket.bindSocketAccept()) {
        std::cout << "Error: bind fail" << std::endl;
        socket.setSocketToInvalid();
        return socket;
    }

    if (!socket.listenSocketAccept()) {
        std::cout << "Error: listen fail" << std::endl;
        socket.setSocketToInvalid();
        return socket;
    }
    this->initialize_is_posible = false;
    return socket;
}