#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QWidget>
#include <QTableWidgetItem>
#include "../client/MatchConfig.h"
#include "../client/Joiner.h"
#include "../client/client_communicator.h"
#include "../client/map_editor/map_saver.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QWidget
{
    Q_OBJECT

public:
    VentanaPrincipal(MatchConfig *match_config, Joiner *joiner, ClientCommunicator *communicator, QWidget *parent = 0);
    ~VentanaPrincipal();

private slots:
    void on_submit_clicked();

    void on_crearSalaButton_clicked();

    void on_continuar_clicked();

    void on_elegirSalaButton_clicked();

    void on_comenzarButton_clicked();

//    void on_reloadButton_clicked();

    void on_comenzarJuego_clicked();

    void on_editarMapa_clicked();

    void on_mapa_cellDoubleClicked(int row, int column);

    void on_guardarMapa_clicked();

    void on_pushButton_clicked();

private:
    Ui::VentanaPrincipal *ui;
    MatchConfig *partida;
    Joiner *joiner;
    ClientCommunicator *communicator;
};

#endif // VENTANAPRINCIPAL_H
