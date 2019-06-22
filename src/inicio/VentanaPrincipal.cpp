#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"
#include <QIcon>
#include <iostream>
#include <string>
#include <list>
#include <QDropEvent>
#include <QCloseEvent>

VentanaPrincipal::VentanaPrincipal(MatchConfig *match_config, Joiner *joinerParam, ClientCommunicator *communicatorParam, QWidget *parent) : QWidget(parent),
                                                                                                                                             ui(new Ui::VentanaPrincipal),
                                                                                                                                             partida(match_config),
                                                                                                                                             joiner(joinerParam),
                                                                                                                                             communicator(communicatorParam)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->entrada->setStyleSheet("QWidget#entrada{border-image: url(resources/img/icon.png) 0 0 0 0 stretch stretch;}");
    ui->inicio->setStyleSheet("QWidget#inicio{border-image: url(resources/img/portada.jpeg) 0 0 0 0 stretch stretch;}QFrame{background-color: rgb(255, 255, 255);}QPushButton#reloadButton_2{border-image: url(resources/img/reload.png) 0 0 0 0 stretch stretch;}");
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_comenzarButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void VentanaPrincipal::on_submit_clicked()
{
    QString vacio("");
    if (ui->host->text() == vacio || ui->port->text() == vacio || ui->nombre->text() == vacio)
        return;
    ui->stackedWidget->setCurrentIndex(2);
    joiner->set(ui->host->text().toStdString(), ui->port->text().toStdString());
    partida->setPlayerName(ui->nombre->text().toStdString());
}

void VentanaPrincipal::on_reloadButton_clicked()
{
    ui->integrantesLista->clear();
    std::vector<std::string> integrantes = communicator->getMates();
    for (size_t i = 0; i < integrantes.size(); i++)
    {
        QString mate(integrantes[i].c_str());
        ui->integrantesLista->addItem(mate);
    }
}

void VentanaPrincipal::closeEvent(QCloseEvent *event) {
    QCoreApplication::exit(EXIT_FAILURE);
}

    void VentanaPrincipal::on_crearSalaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    partida->setMode("new");
}

void VentanaPrincipal::on_continuar_clicked()
{
    QString vacio("");
    if (ui->nombreSala->text() == vacio)
        return;
    ui->sala->setText(ui->nombreSala->text());
    partida->setSalaName(ui->nombreSala->text().toStdString());
    communicator->set(std::move(joiner->setSocket()), partida->getMode(), partida->getSalaName(), partida->getPlayerName());
    std::vector<std::string> integrantes = communicator->getMates();
    for (size_t i = 0; i < integrantes.size(); i++)
    {
        QString mate(integrantes[i].c_str());
        ui->integrantesLista->addItem(mate);
    }
    ui->stackedWidget->setCurrentIndex(4);
}

void VentanaPrincipal::on_elegirSalaButton_clicked()
{
    partida->setMode("join");
    ui->stackedWidget->setCurrentIndex(3);
}

void VentanaPrincipal::on_comenzarJuego_clicked()
{
    communicator->addMessageToSend("start");
    QApplication::quit();
}

void VentanaPrincipal::on_editarMapa_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->mapa->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void VentanaPrincipal::on_mapa_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *item = ui->mapa->item(row,column);
    QString vacio("");
    if (item == 0) return;
    std::cout << item->text().toStdString().c_str() << std::endl;
    item->setText(vacio);
    QIcon icon;
    item->setIcon(icon);
}

void VentanaPrincipal::on_guardarMapa_clicked()
{
    QTableWidget *mapa = ui->mapa;
    MapSaver mapSaver("json.prueba");
    for (int i=0;i<mapa->columnCount();i++) {
        for (int j=0;j<mapa->rowCount();j++) {
            QTableWidgetItem *item = mapa->item(i,j);
            if(item == 0) continue;
            QString vacio("");
            if (item->text() == vacio) continue;
            mapSaver.addObject(item->text().toStdString() + "," + std::to_string(j - ui->mapa->columnCount() / 2) + "," + std::to_string(-1 * (i - ui->mapa->rowCount() / 2)));
        }
    }
    mapSaver.writeFile();
    ui->mapa->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void VentanaPrincipal::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->mapa->setColumnCount(ui->ancho->text().toInt());
    ui->mapa->setRowCount(ui->alto->text().toInt());
}
