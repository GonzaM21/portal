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
#include "inicio/include/Inicio.h"
#include <QApplication>

int ejecutarVentana(int argc, char *argv[] ,std::string &host, std::string &port, std::string &player_name)
{
    //char *a[20];
    //int n = 0;
    //QApplication app(n, a);
    // Instancio el greeter
    //Inicio inicio(host,port,player_name);
    //inicio.show();
    // Arranca el loop de la UI
    //return app.exec();
    //app.exit();
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
        std::string host, port, player_name;
        ejecutarVentana(argc,argv,host,port,player_name);
        host = "127.0.0.1";
        port = "8080";
        Joiner joiner(host,port);
        std::string mode = "new";
        std::string room_name = "sala";

        ModelFacade model_facade;
        ClientCommunicator communicator(std::move(joiner.setSocket()), 
            mode, room_name, player_name, &model_facade);

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