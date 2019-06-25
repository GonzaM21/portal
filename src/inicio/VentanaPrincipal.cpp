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
                                                                                                                                             communicator(communicatorParam),
                                                                                                                                             id_gate(0) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->entrada->setStyleSheet("QWidget#entrada{border-image: url(resources/img/icon.png) 0 0 0 0 stretch stretch;}");
    ui->inicio->setStyleSheet("QWidget#inicio{border-image: url(resources/img/portada.jpeg) 0 0 0 0 stretch stretch;}QFrame{background-color: rgb(255, 255, 255);}");
}

VentanaPrincipal::~VentanaPrincipal() {
    delete ui;
}

void VentanaPrincipal::on_comenzarButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void VentanaPrincipal::on_submit_clicked() {
    QString vacio("");
    if (ui->host->text() == vacio || ui->port->text() == vacio || ui->nombre->text() == vacio)
        return;
    ui->stackedWidget->setCurrentIndex(2);
    joiner->set(ui->host->text().toStdString(), ui->port->text().toStdString());
    partida->setPlayerName(ui->nombre->text().toStdString());
}

void VentanaPrincipal::closeEvent(QCloseEvent *event) {
    QCoreApplication::exit(EXIT_FAILURE);
}

void VentanaPrincipal::on_crearSalaButton_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
    partida->setMode("new");
}

void VentanaPrincipal::on_continuar_clicked() {
    QString vacio("");
    if (ui->nombreSala->text() == vacio)
        return;
    ui->sala->setText(ui->nombreSala->text());
    partida->setSalaName(ui->nombreSala->text().toStdString());
    communicator->set(std::move(joiner->setSocket()), partida->getMode(), partida->getSalaName(), partida->getPlayerName());
    ui->stackedWidget->setCurrentIndex(4);
}

void VentanaPrincipal::on_elegirSalaButton_clicked() {
    partida->setMode("join");
    ui->stackedWidget->setCurrentIndex(3);
}

void VentanaPrincipal::on_comenzarJuego_clicked() {
    communicator->addMessageToSend("start");
    QCoreApplication::exit(EXIT_SUCCESS);
}

void VentanaPrincipal::on_editarMapa_clicked() {
    ui->stackedWidget->setCurrentIndex(5);
    ui->asociarPop->hide();
    ui->mapa->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void VentanaPrincipal::removeGate(QTableWidgetItem* item) {
    int id = -1;
    for (auto gate  : gates) {
        if (gate.second == item) {
            id = gate.first;
            break;  
        }
    }
    if (id == -1) {
        return;
    }
    gates.erase(id);
    gatesPos.erase(id);
    QString vacio("");
    QIcon icon;
    ui->mapa->item(item->row() + 1, item->column())->setText(vacio);
    ui->mapa->item(item->row() + 1, item->column())->setIcon(icon);
    item->setText(vacio);
    item->setIcon(icon);
    removeButtons(id);
}

void VentanaPrincipal::removeButtons(int &id) {
    std::vector<QTableWidgetItem*> buttonsDel = buttons.at(id);
    for (auto button  : buttonsDel) {
        QString vacio("");
        button->setText(vacio);
        QIcon icon;
        button->setIcon(icon);
    }
    buttons.erase(id);
}

void VentanaPrincipal::removeButton(QTableWidgetItem *item) {
    for (auto& buttonsIt : buttons) {
        std::vector<QTableWidgetItem*>::iterator position = std::find(buttonsIt.second.begin(), buttonsIt.second.end(), item);
        if (position != buttonsIt.second.end()) {
            buttonsIt.second.erase(position);
            int index = std::distance(buttonsIt.second.begin(), position);
            std::vector<std::vector<int>> &buttonsPosAct = buttonsPos.at(buttonsIt.first);
            buttonsPosAct.erase(buttonsPosAct.begin() + index);
            break;
        }
    }
}

void VentanaPrincipal::on_mapa_cellDoubleClicked(int row, int column) {
    QTableWidgetItem *item = ui->mapa->item(row,column);
    if ((item == 0) || (row == 0) || (row == ui->mapa->rowCount() - 1) ||
        (column == 0) || (column == ui->mapa->columnCount() - 1) ||
        ((row == ui->mapa->rowCount() - 2 || row == ui->mapa->rowCount() - 3) && column == ui->mapa->columnCount() / 2 - 1))
        return;
    if (item->text().toStdString() == "Gate") {removeGate(item); return;}
    if (item->text().toStdString() == "Button") {removeButton(item);}
    QString vacio("");
    item->setText(vacio);
    QIcon icon;
    item->setIcon(icon);
    setGround();
}

void VentanaPrincipal::on_mapa_cellChanged(int row, int column) {
    QTableWidgetItem *item = ui->mapa->item(row, column);
    QTableWidgetItem *itemRowAnt = ui->mapa->item(row -1 , column);
    QTableWidgetItem *itemRow = ui->mapa->item(row + 1, column);
    QString vacio("");
    if (item == 0)
            return;
    if (item->text().toStdString() == "Button") {
        ui->asociarPop->show();
        last_button = item;
        std::vector<int> vector{row, column};
        last_button_pos = vector;
        setGround();
        return;
    }
    if (item->text().toStdString() == "Chell") {
        return;
    }    
    if (item->text().toStdString() != "Gate") {
        setGround();
        return;
    }
    if (itemRowAnt != 0 && itemRowAnt->text().toStdString() == "Gate") {
        setGround();
        return;
    }
    if ((itemRow == 0 || (itemRow != 0 && itemRow->text() == vacio)) && item->text().toStdString() == "Gate"){
        std::vector<int> vector{row,column};
        gatesPos[id_gate] = vector;
        gates[id_gate] = item;
        id_gate++;
        ui->mapa->setItem(row+1,column,new QTableWidgetItem(*item));
    } else {
        if (item->text().toStdString() == "Gate") {
            item->setText(vacio);
            QIcon icon;
            item->setIcon(icon);
        }
    }
}

void VentanaPrincipal::on_guardarMapa_released() {
    QTableWidget *mapa = ui->mapa;
    MapSaver mapSaver("json_prueba12");
    for (int i = 0; i < mapa->rowCount(); i++) {
        for (int j = 0; j < mapa->columnCount(); j++) {
            QTableWidgetItem *item = mapa->item(i, j);
            if (item == 0)
                continue;
            QString vacio("");
            QString button("Button");
            QString gate("Gate");
            QString chell("Chell");
            if (item->text() == vacio || item->text() == button || item->text() == gate || item->text() == chell)
                continue;
            mapSaver.addObject(item->text().toStdString() + "," + std::to_string(j + 1 - (ui->mapa->columnCount() / 2)) + "," + std::to_string(-i - 1 + (ui->mapa->rowCount())));
        }
    }
    std::map<int, std::vector<QTableWidgetItem *>>::iterator button_it;
    for (button_it = buttons.begin(); button_it != buttons.end(); button_it++) {
        for (size_t j = 0; j < button_it->second.size(); j++) {
            mapSaver.addObject("Button," + std::to_string(buttonsPos.at(button_it->first)[j][1] + 1 - (ui->mapa->columnCount() / 2)) + "," + std::to_string(-buttonsPos.at(button_it->first)[j][0] - 1 + ui->mapa->rowCount()) + "," + std::to_string(button_it->first));
        }
    }
    std::map<int, QTableWidgetItem*>::iterator gate_it;
    for (gate_it = gates.begin(); gate_it != gates.end(); gate_it++) {
        mapSaver.addObject("Gate," + std::to_string(gatesPos.at(gate_it->first)[1] + 1 - (ui->mapa->columnCount() / 2)) + "," + std::to_string(-gatesPos.at(gate_it->first)[0] - 1 + (ui->mapa->rowCount())) + "," + std::to_string(gate_it->first));
    }
    mapSaver.writeFile();
    ui->mapa->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void VentanaPrincipal::on_asociar_clicked() {
    ui->asociarPop->hide();
    std::vector<QTableWidgetItem *> vectores{last_button};
    std::vector<int> vectorpos{last_button_pos[0], last_button_pos[1]};
    std::vector<std::vector<int>> vectorespos{vectorpos};
    if (buttonsPos.find(ui->numPuerta->text().toInt()) == buttonsPos.end()) {
        buttonsPos[ui->numPuerta->text().toInt()] = vectorespos;
    } else {
        buttonsPos[ui->numPuerta->text().toInt()].push_back(vectorpos);
    }
    if (buttons.find(ui->numPuerta->text().toInt()) == buttons.end()) {
        buttons[ui->numPuerta->text().toInt()] = vectores; 
    } else {
        buttons[ui->numPuerta->text().toInt()].push_back(last_button);
    }
    return;
}
void VentanaPrincipal::on_pushButton_clicked() {
    QString vacio("");
    if (ui->alto->text() == vacio || ui->ancho->text() == vacio)
        return;
    ui->stackedWidget->setCurrentIndex(6);
    ui->mapa->setColumnCount(ui->ancho->text().toInt());
    ui->mapa->setRowCount(ui->alto->text().toInt());
    setGround();
}

void VentanaPrincipal::setGround() {
    QIcon iconChell("resources/qt/Chell.png");
    QString chell("Chell");
    ui->mapa->setItem(ui->mapa->rowCount() - 2, ui->mapa->columnCount() / 2 - 1, new QTableWidgetItem(iconChell, chell));
    ui->mapa->setItem(ui->mapa->rowCount() - 3, ui->mapa->columnCount() / 2 - 1, new QTableWidgetItem(iconChell, chell));
    QIcon icon("resources/qt/Metal_block.png");
    QString metal("Metal");
    for (int i = 0; i < ui->mapa->rowCount(); i++) {
        if (ui->mapa->item(i, 0) == 0 || ui->mapa->item(i, 0)->text() != metal) {
            ui->mapa->setItem(i, 0, new QTableWidgetItem(icon, metal));
            ui->mapa->item(i, 0)->setFlags(ui->mapa->item(i, 0)->flags() & ~Qt::ItemIsEditable);
        }
        if (ui->mapa->item(i, ui->mapa->columnCount() - 1) == 0 || ui->mapa->item(i, ui->mapa->columnCount() - 1)->text() != metal) {
            ui->mapa->setItem(i, ui->mapa->columnCount() - 1, new QTableWidgetItem(icon, metal));
            ui->mapa->item(i, ui->mapa->columnCount() - 1)->setFlags(ui->mapa->item(i, ui->mapa->columnCount() - 1)->flags() & ~Qt::ItemIsEditable);
        }
    }
    for (int i = 0; i < ui->mapa->columnCount(); i++) {
        if (ui->mapa->item(0,i) == 0 || ui->mapa->item(0, i)->text() != metal) {
            ui->mapa->setItem(0, i, new QTableWidgetItem(icon, metal));
            ui->mapa->item(0, i)->setFlags(ui->mapa->item(0, i)->flags() & ~Qt::ItemIsEditable);
        }
        if (ui->mapa->item(ui->mapa->rowCount() - 1, i) == 0 || ui->mapa->item(ui->mapa->rowCount() - 1, i)->text() != metal) {
            ui->mapa->setItem(ui->mapa->rowCount() - 1, i, new QTableWidgetItem(icon, metal));
            ui->mapa->item(ui->mapa->rowCount() - 1, i)->setFlags(ui->mapa->item(ui->mapa->rowCount() - 1, i)->flags() & ~Qt::ItemIsEditable);
        }
    }
}