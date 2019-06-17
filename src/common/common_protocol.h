#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string.h>
#include <string>
#include <iostream>
#include "../common/common_socket_connect.h"

class Protocol {
    private:
        SocketConnect socket;
        void sendInt32(uint32_t num);
        void recieveInt32(uint32_t *num);
    public:
        explicit Protocol(SocketConnect socket);
        Protocol() {};
        void setSocket(SocketConnect socket); 
        ~Protocol() = default;
        Protocol& operator>>(std::string &string);
        Protocol& operator>>(uint8_t &num);
        Protocol& operator>>(uint16_t &num);
        Protocol& operator>>(uint32_t &num);
        Protocol& operator<<(uint8_t &num);
        Protocol& operator<<(uint16_t &num);
        Protocol& operator<<(uint32_t &num);
        Protocol& operator<<(std::string &string);
        void closeProtocol();
};

#endif
