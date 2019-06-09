#include "Joiner.h"

Joiner::Joiner(const char* &hostn,const char* &srvn) {
    this->hostn = hostn;
    this->srvn =srvn;
    this->is_valid = true;
}

SocketConnect Joiner::setSocket() {
    SocketConnect socket;
    if (!socket.addrinfo(this->hostn, this->srvn)) {
        std::cout << "Error: addrinfo fail" << std::endl;
        this->is_valid = false;
        return socket;
    }

    if (!socket.socketConnect()) {
        std::cout << "Error: connect fail" << std::endl;
        this->is_valid = false;
        return socket;
    }
    return socket;    
}

bool Joiner::isValid() {
    return this->is_valid;
}