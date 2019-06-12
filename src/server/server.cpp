#include <iostream>
#include <string>
#include "server_initializer.h"
#include "../server/server_client_acceptor.h"
#include "../server/server_socket_accept.h"
#include "../server/server_room_game.h"
#include "../server/server_room_manager.h"
#include "../common/common_socket_connect.h"
#include "../common/common_protocol.h"

int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            std::cout << "Error: invalid arguments." << std::endl;
            return 0;
        }

        Initializer initializer;
        SocketAccept socket = initializer.initialiceSocketAccept(argv[1]);
        ClientAcceptor *acceptor = new ClientAcceptor(socket);

        acceptor->start();
    
        bool continue_running = true;
        while (continue_running) {
            std::string input;
            std::cin >> input;
            if (input == "q") continue_running = false;
        }
        acceptor->endExecution();
        acceptor->join();
        delete acceptor;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: unknown" << std::endl;
    }

    return 0;
}
