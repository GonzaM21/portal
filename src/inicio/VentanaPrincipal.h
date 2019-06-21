#ifndef __VENTANAPRINCIPAL_H__
#define __VENTANAPRINCIPAL_H__

#include "../client/MatchConfig.h"
#include "../client/Joiner.h"
#include <QWidget>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QWidget
{
    Q_OBJECT

public:
    VentanaPrincipal(MatchConfig *match_config, Joiner *joiner, ClientCommunicator* communicator, QWidget *parent = 0);
    virtual ~VentanaPrincipal();

private slots:
    void on_submit_clicked();

    void on_crearSalaButton_clicked();

    void on_crearSalaButton_2_clicked();

    void on_elegirSalaButton_clicked();

    void on_comenzarButton_clicked();

    void on_reloadButton_2_clicked();

    void on_comenzarJuego_clicked();

private:
    Ui::VentanaPrincipal *ui;
    MatchConfig* partida;
    Joiner* joiner;
    ClientCommunicator* communicator;
};

#endif // VENTANAPRINCIPAL_H
