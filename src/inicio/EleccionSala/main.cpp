#include "eleccionsala.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EleccionSala w;
    w.show();

    return a.exec();
}
