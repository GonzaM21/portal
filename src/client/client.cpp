#include <iostream>
#include <string>
#include <thread>
#include "renderable.h"
#include "client/client_communicator.h"
#include "Joiner.h"
#include "common/common_socket_connect.h"
#include "common/common_protocol.h"
#include "client/event_handler_thread.h"
#include "client/Message_sender.h"
#include "map_editor/interface.h"
#include "inicio/VentanaPrincipal.h"
#include "client/ConfigPartida.h"
#include <QApplication>

int ejecutarVentana(int argc, char *argv[], ConfigPartida* configPartida, Joiner* joiner, ClientCommunicator* communicator)
{
    QApplication app(argc, argv);
    // Instancio el greeter
    VentanaPrincipal ventanaprincipal(configPartida, joiner, communicator);
    ventanaprincipal.show();
    // Arranca el loop de la UI
    return app.exec();
    app.exit();
    return 0;
} 

int main(int argc, char *argv[])
{
    //if (argc != 6) {
    //    std::cout << "Error: invalid arguments." << std::endl;
    //    return 0;
    //}
    try {
        if (argc == 2) {
            std::string file_name("json_file");
            Interface interface(file_name);
            interface.createMap();
            return 0;
        }
        ConfigPartida configPartida;
        Joiner joiner;
        ModelFacade model_facade;
        ClientCommunicator communicator(&model_facade);
        ejecutarVentana(argc, argv, &configPartida, &joiner,&communicator);
        // std::string mode = configPartida.getMode();
        // std::string room_name = configPartida.getSalaName();
        // std::string player_name = configPartida.getPlayerName();

        if (!joiner.isValid()) return 0; 

        MessageSender sender(&communicator, &model_facade);
        Renderable *renderer_thread = new Renderable(&model_facade,&communicator);
        EventHandlerThread* handler = new EventHandlerThread(sender,&model_facade);
        renderer_thread->start();
        handler->start();
        communicator.startExecution();
        handler->endExecution();
        handler->join();
        renderer_thread->endExecution();
        renderer_thread->join();
        delete renderer_thread;
        delete handler;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: unknown" << std::endl;
    }
    return 0;
}


        /*std::vector<Thread*> threads;
        threads.push_back(new Renderable(&model_facade,&communicator));
        threads.push_back(new EventHandlerManager(&communicator));

        //for (int i = 0; i< threads.size(); i++) {
        //    threads[i]->start();
        //}
        //for (int i= 0;i< threads.size(); i++) {
        //    threads[i]->endExecution();
        //    threads[i]->join();
        //    delete threads[i];
        //}*/