#ifndef CLIENT_COMMUNICATOR_H
#define CLIENT_COMMUNICATOR_H
#include <thread>
#include "../common/common_protocol.h"
#include "../common/common_socket_connect.h"
#include "../common/common_cola_protegida.h"
#include "../common/Thread.h"
#include "data_container.h"

class ClientCommunicator : public Thread {
private:
    Protocol protocol;
    bool continue_running;
    std::thread sender;
    ColaProtegida receiver_queue;
    ColaProtegida sender_queue;
    DataContainer &data_container;

public: 
    ClientCommunicator(DataContainer &data_container);
    ~ClientCommunicator();
    void set(SocketConnect socket,
             std::string mode, std::string room_name,
             std::string player_name);
    void receiveMessage();
    void sendMessage();
    void endExecution();
    virtual void run() override;
    bool isRunnning();
    void addMessageToSend(std::string message);
    void parseMatesForInitialWindow(std::string &message);
    std::string popMessageReceived();
    std::vector<std::string> getMates(); //BORRRAR ESTA MIERDA
    std::string getMode();
};

#endif
