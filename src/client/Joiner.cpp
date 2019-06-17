#include "Joiner.h"

Joiner::Joiner() {
    this->is_valid = true;
}

SocketConnect Joiner::setSocket() {
    SocketConnect socket;
    if (!socket.addrinfo(this->hostn.c_str(), this->srvn.c_str()))
    {
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

void Joiner::set(std::string hostn, std::string srvn)
{
    this->hostn = hostn;
    this->srvn = srvn;
}

bool Joiner::isValid() {
    return this->is_valid;
}