#ifndef QT_EXECUTOR_H
#define QT_EXECUTOR_H
#include "../inicio/VentanaPrincipal.h"
#include "MatchConfig.h"
#include <QApplication>
#include <string>

class QtExecutor {
private:
    MatchConfig config;
public:
    QtExecutor() = default;
    ~QtExecutor() = default;
    int executeWindow(int argc, char *argv[], Joiner* joiner, ClientCommunicator* communicator);
};

#endif