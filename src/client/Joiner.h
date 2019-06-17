#ifndef JOINER_H
#define JOINER_H
#include <thread>
#include "../common/common_protocol.h"
#include "../common/common_socket_connect.h"

class Joiner {
private:
    bool is_valid;
    std::string hostn;
    std::string srvn;

public:
    Joiner();
    ~Joiner() = default;
    void set(std::string hostn,std::string srvn);
    SocketConnect setSocket();
    bool isValid();
};

#endif