#include "partita.h"
#include "ui_partita.h"

Partita::Partita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Partita)
{
    ui->setupUi(this);
}

Partita::~Partita()
{
    delete ui;
}
