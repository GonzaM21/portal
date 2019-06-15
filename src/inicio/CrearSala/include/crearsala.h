#ifndef CREARSALA_H
#define CREARSALA_H

#include <QWidget>

namespace Ui {
class CrearSala;
}

class CrearSala : public QWidget
{
    Q_OBJECT

public:
    explicit CrearSala(QWidget *parent = 0);
    ~CrearSala();

private:
    Ui::CrearSala *ui;
};

#endif // CREARSALA_H
