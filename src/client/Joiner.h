#ifndef JOINER_H
#define JOINER_H
#include <thread>
#include "../common/common_protocol.h"
#include "../common/common_socket_connect.h"

class Joiner {
private:
    bool is_valid;
    const char* hostn;
    const char* srvn;

public:
    Joiner(std::string &hostn,std::string &srvn);
    ~Joiner() = default;
    SocketConnect setSocket();
    bool isValid();
};

#endif