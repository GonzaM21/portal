#include "salaespera.h"
// Cargo el archivo generado por uic, leer el CMakelist.txt para mas info
#include "ui_SalaEspera.h"
#include <string>
#include <iostream>
#include <QApplication>

SalaEspera::SalaEspera(std::string &host, std::string &port, std::string &player_name, QWidget *parent)
    : QWidget(parent), player_name(player_name), host(host), port(port)
{
    // Instancio la configuracion generada por el designer y uic
    Ui::SalaEspera SalaEspera;
    // Configuro este widget para use esa configuracion
    SalaEspera.setupUi(this);
    connectEvents();
}

void SalaEspera::updateGreetings()
{
    /**
     * findChild es un metodo de qObject que permite buscar un widget hijo
     * segun su nombre. Si observamos el codigo generado en ui_SalaEspera
     * cada uno de los objetos recibe un nombre mediante la funcion
     * setObjectName(QString nombre)
     **/
    QLineEdit *inputName = findChild<QLineEdit *>("nombre");
    this->player_name = inputName->text().toStdString();
    std::cout << this->player_name.c_str() << std::endl;
    QLineEdit *inputHost = findChild<QLineEdit *>("host");
    this->host = inputHost->text().toStdString();
    std::cout << this->host.c_str() << std::endl;
    QLineEdit *inputPort = findChild<QLineEdit *>("port");
    this->port = inputPort->text().toStdString();
    std::cout << this->port.c_str() << std::endl;
    QCoreApplication::quit();
}

void SalaEspera::connectEvents()
{
    // Conecto el evento del boton
    QPushButton *buttonGreet = findChild<QPushButton *>("submit");
    QObject::connect(buttonGreet, &QPushButton::clicked,
                     this, &SalaEspera::updateGreetings);
}
