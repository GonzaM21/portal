#ifndef CLIENT_COMMUNICATOR_H
#define CLIENT_COMMUNICATOR_H
#include <thread>
#include "common/common_protocol.h"
#include "common/common_socket_connect.h"
#include "vista/ModelFacade.h"
#include "common/common_cola_protegida.h"
#include "client_deserializer.h"

class ClientCommunicator {
private:
    Protocol protocol;
    bool continue_running;
    std::thread sender;
    ClientDeserializer deserializer;
    ColaProtegida message_queue;
    bool received_map = false;

public : ClientCommunicator( ModelFacade *model_facade);
    ~ClientCommunicator();
    void set(SocketConnect socket,
             std::string mode, std::string room_name,
             std::string player_name); 
    void receiveMessage();
    std::vector<std::string> getMates();
    void sendMessage();
    void endExecution();
    void startExecution();
    bool getReceivedMap();
    void receiveMap();
    bool isRunnning();
    void addMessageToSend(std::string message);
};

#endif
