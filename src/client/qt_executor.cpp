#include "qt_executor.h"
#include "inicio/Application.h"

int QtExecutor::executeWindow(int argc, char *argv[], 
    Joiner* joiner, ClientCommunicator* communicator) {
    MatchConfig config;
    Application app(argc, argv);
    std::setlocale(LC_ALL,"en_US.UTF-8");
    VentanaPrincipal ventanaprincipal(&config, joiner, communicator);
    ventanaprincipal.show();
    return app.exec();
} 