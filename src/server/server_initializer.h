#ifndef INITIALIZER
#define INITIALIZER
#include "../server/server_socket_accept.h"

class Initializer {
private:
    bool initialize_is_posible;

public:
    Initializer();
    ~Initializer() =default;
    SocketAccept initialiceSocketAccept(char *&port);
};

#endif
