#ifndef CLIENT_COMMUNICATOR
#define CLIENT_COMMUNICATOR
#include <thread>
#include "../common/common_protocol.h"
#include "../common/common_socket_connect.h"
#include "../vista/ModelFacade.h"
#include "../common/common_cola_protegida.h"

class ClientCommunicator {
private:
    Protocol protocol;
    bool continue_running;
    std::thread sender;
    ModelFacade *model_facade;
    ColaProtegida message_queue;

public:
    ClientCommunicator(SocketConnect socket,
                       std::string &mode, std::string &room_name,
                       std::string &player_name, ModelFacade *model_facade);
    ~ClientCommunicator();
    void receiveMessage();
    void sendMessage();
    void endExecution();
    void startExecution();
    void splitMessage(std::string &message, std::vector<std::string> &arguments);
    void addMessageToSend(std::string message);
};

#endif
