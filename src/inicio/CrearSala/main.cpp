#include "crearsala.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrearSala w;
    w.show();

    return a.exec();
}
