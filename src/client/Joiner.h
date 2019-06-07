#ifndef JOINER_H
#define JOINER_H
#include <thread>
#include "../common/common_protocol.h"
#include "../common/common_socket_connect.h"

class Joiner {
private:
    bool is_valid;
    char* hostn;
    char* srvn;

public:
    Joiner(char* &hostn,char* &srvn);
    ~Joiner() = default;
    SocketConnect setSocket();
    bool isValid();
};

#endif