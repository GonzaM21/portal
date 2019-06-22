#include "qt_executor.h"

int QtExecutor::executeWindow(int argc, char *argv[], 
    Joiner* joiner, ClientCommunicator* communicator) {
    MatchConfig config;
    QApplication app(argc, argv);
    VentanaPrincipal ventanaprincipal(&config, joiner, communicator);
    ventanaprincipal.show();
    return app.exec();
} 