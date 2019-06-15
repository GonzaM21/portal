#include "Joiner.h"

Joiner::Joiner(std::string &hostn,std::string &srvn) {
    this->hostn = hostn.c_str();
    this->srvn = srvn.c_str();
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