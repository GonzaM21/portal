#include <iostream>
#include <string>
#include <thread>
#include "renderable.h"
#include "client_communicator.h"
#include "Joiner.h"
#include "../common/common_socket_connect.h"
#include "../common/common_protocol.h"
#include "../vista/EventsHandler.h"


int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cout << "Error: invalid arguments." << std::endl;
        return 0;
    }
    try {
        Joiner joiner(argv[1],argv[2]);
        std::string mode = argv[3];
        std::string room_name = argv[4];
        std::string player_name = argv[5];

        ModelFacade model_facade;
        ClientCommunicator communicator(std::move(joiner.setSocket()), 
            mode, room_name, player_name, &model_facade);

        if (!joiner.isValid()) return 0;

        Renderable *renderer_thread = new Renderable(&model_facade);
        renderer_thread->start();
        communicator.startExecution();
        
        renderer_thread->endExecution();
        renderer_thread->join();
        delete renderer_thread;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: unknown" << std::endl;
    }
    return 0;
}
