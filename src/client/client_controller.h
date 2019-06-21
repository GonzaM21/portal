#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H
#include "event_handler_thread.h"
#include "qt_executor.h"
#include "renderable.h"
#include "scene_manager.h"
#include "Joiner.h"
#include "client_deserializer.h"
#include "client_communicator.h"
#include "data_container.h"

class ClientController {
private:
    ClientCommunicator* communicator;
    EventHandlerThread* handler;
    Renderable* renderer_thread;
    bool continue_running;

    void initializeCommunication(); 
    void evaluateDataContainer(DataContainer *data_container);

public:
    ClientController();
    ~ClientController() =default;
    int runInitialWindow(int argc, char *argv[]);
    void endExecution();
    void mainLoop();
};

#endif
