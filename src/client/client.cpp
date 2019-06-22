#include <iostream>
#include <string>
#include <thread>
#include "renderable.h"
#include "client_communicator.h"
#include "Joiner.h"
#include "event_handler_thread.h"
#include "Message_sender.h"
#include "client_controller.h"
#include "../common/common_socket_connect.h"
#include "../common/common_protocol.h"

int main(int argc, char *argv[])
{
    try {
        ClientController controller;
        int rv = controller.runInitialWindow(argc,argv); 
        if (rv == 1) {
            controller.failureExit();
            return 0;
        }
        controller.mainLoop();
        controller.endExecution();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: unknown" << std::endl;
    }
    return 0;
}
