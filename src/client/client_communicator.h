#ifndef CLIENT_COMMUNICATOR_H
#define CLIENT_COMMUNICATOR_H
#include <thread>
#include "common/common_protocol.h"
#include "common/common_socket_connect.h"
#include "vista/ModelFacade.h"
#include "common/common_cola_protegida.h"

class ClientCommunicator {
private:
    Protocol protocol;
    bool continue_running;
    std::thread sender;
    ModelFacade *model_facade;
    ColaProtegida message_queue;
    bool received_map = false;

public : ClientCommunicator(SocketConnect socket,
    std::string &mode, std::string &room_name,
    std::string &player_name, ModelFacade *model_facade);
    ~ClientCommunicator();
    void receiveMessage();
    void sendMessage();
    void endExecution();
    void startExecution();
    bool getReceivedMap();
    void receiveMap();
    void splitMessage(std::string &message, std::vector<std::string> &arguments);
    void addMessageToSend(std::string message);
};

#endif
