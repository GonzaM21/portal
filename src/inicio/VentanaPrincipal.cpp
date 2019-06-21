#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"
#include <string>
#include <list>

VentanaPrincipal::VentanaPrincipal(MatchConfig *match_config, Joiner* joinerParam,ClientCommunicator* communicatorParam,QWidget *parent) : QWidget(parent),
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

void VentanaPrincipal::on_comenzarButton_clicked() {
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

void VentanaPrincipal::on_reloadButton_2_clicked() {
    ui->integrantesLista->clear();
    std::vector<std::string> integrantes = communicator->getMates();
    for (size_t i = 0; i < integrantes.size(); i++)
    {
        QString mate(integrantes[i].c_str());
        ui->integrantesLista->addItem(mate);
    }
}

void VentanaPrincipal::on_crearSalaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    partida->setMode("new");
}

void VentanaPrincipal::on_crearSalaButton_2_clicked()
{
    QString vacio("");
    if (ui->nombreSala->text() == vacio)
        return;
    ui->sala->setText(ui->nombreSala->text());
    partida->setSalaName(ui->nombreSala->text().toStdString());
    communicator->set(std::move(joiner->setSocket()),partida->getMode(),partida->getSalaName(),partida->getPlayerName());
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
    // if(ui->listaSalas->selectedItems().isEmpty()) return;
    partida->setMode("join");
    partida->setSalaName("sala");
    // ui->sala->setText(ui->listaSalas->selectedItems().at(0)->text());
    communicator->set(std::move(joiner->setSocket()), partida->getMode(), partida->getSalaName(), partida->getPlayerName());
    std::vector<std::string> integrantes = communicator->getMates();
    for (size_t i = 0; i < integrantes.size(); i++)
    {
        QString mate(integrantes[i].c_str());
        ui->integrantesLista->addItem(mate);
    }
    ui->stackedWidget->setCurrentIndex(4);
}

void VentanaPrincipal::on_comenzarJuego_clicked() {
    communicator->addMessageToSend("start");
    QApplication::quit();
}
