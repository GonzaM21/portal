#include "eleccionsala.h"
#include "ui_eleccionsala.h"

EleccionSala::EleccionSala(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EleccionSala)
{
    ui->setupUi(this);
}

EleccionSala::~EleccionSala()
{
    delete ui;
}
