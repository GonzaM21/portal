#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string.h>
#include <string>
#include <iostream>
#include "../common/common_socket_connect.h"

/*
* Clase para enviar informac ion atraves de socekts
*/

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

        //Recibe un string atraves de un socket
        Protocol& operator>>(std::string &string);

        //Recibe un uint8 atraves de un socket
        Protocol& operator>>(uint8_t &num);

        //Recibe un uint16 atraves de un socket
        Protocol& operator>>(uint16_t &num);

        //Recibe un uint32 atraves de un socket
        Protocol& operator>>(uint32_t &num);

        //Envia un uint8 atraves de un socket
         Protocol& operator<<(uint8_t &num);

        //Envia un uint16 atraves de un socket 
        Protocol& operator<<(uint16_t &num);

        //Envia un uint32 atraves de un socket 
        Protocol& operator<<(uint32_t &num);

        //Envia un string atraves de un socket 
        Protocol& operator<<(std::string &string);
        void closeProtocol();
};

#endif
