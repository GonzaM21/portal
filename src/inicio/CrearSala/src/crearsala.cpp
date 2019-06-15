#include "crearsala.h"
#include "ui_crearsala.h"

CrearSala::CrearSala(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrearSala)
{
    ui->setupUi(this);
}

CrearSala::~CrearSala()
{
    delete ui;
}
