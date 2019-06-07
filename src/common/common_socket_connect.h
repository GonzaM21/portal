#ifndef SOCKET_CONNECT_H
#define SOCKET_CONNECT_H
#define RESPONSE_MAX_LEN 50

#include <string>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

class SocketConnect {
    private:
        int s;
        int skt;
        struct addrinfo hints;
        struct addrinfo *result;
        struct addrinfo *ptr;
        void set_hints_socket();

    public:
        SocketConnect();
        explicit SocketConnect(int socket);
        bool addrinfo(const char *hostn, const char *srvn);
        bool socketConnect();

        //Indica con un booleano si el socket es valido
        bool isValid();
        //Cierra la conexion del socket.
        void closeConnection();
        ~SocketConnect() = default;
        //Recibe un string y un int.
        //Envia un mensaje al socket el cual esta conectado.
        int sendMessage(char *buf, int size);

        //Recibe un string y un int.
        //Espera un mensaje del socket al cual esta conectado.
        int reciveMessage(char *buf, int size);
        SocketConnect& operator=(const SocketConnect&) = delete;
        SocketConnect(SocketConnect&& other);
        SocketConnect& operator=(SocketConnect&& other);
};

#endif
