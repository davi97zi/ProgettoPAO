#include "battaglia.h"
#include "ui_battaglia.h"

Battaglia::Battaglia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battaglia)
{
    ui->setupUi(this);
}

Battaglia::~Battaglia()
{
    delete ui;
}
