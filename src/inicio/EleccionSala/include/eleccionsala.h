#ifndef ELECCIONSALA_H
#define ELECCIONSALA_H

#include <QWidget>

namespace Ui {
class EleccionSala;
}

class EleccionSala : public QWidget
{
    Q_OBJECT

public:
    explicit EleccionSala(QWidget *parent = 0);
    ~EleccionSala();

private:
    Ui::EleccionSala *ui;
};

#endif // ELECCIONSALA_H
