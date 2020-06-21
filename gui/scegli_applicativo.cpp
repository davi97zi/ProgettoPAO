#include "scegli_applicativo.h"

ScegliApplicativo::ScegliApplicativo(QWidget *parent) : QWidget(parent)
{
    titolo = new QLabel("LIBERTY GAME");
    titolo->setStyleSheet("QLabel{font-size: 20px; font-weight: bold;padding: 0.5em; margin: 0.5em;}");
    titolo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    gioca = new QPushButton("Gioca");
    gioca->setObjectName("gioca");
    gioca->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    gioca->setStyleSheet("QPushButton{border-style: outset; border-width: 1px;border-color: black; min-width: 10em;padding: 6px;}"
                         "QPushButton:pressed {background-color: beige; border-style: inset;}");

    storico = new QPushButton("Storico");
    storico->setObjectName("storico");
    storico->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    storico->setStyleSheet("QPushButton{border-style: outset; border-width: 1px;border-color: black; min-width: 10em;padding: 6px;}"
                         "QPushButton:pressed {background-color: beige; border-style: inset;}");


    verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(titolo, 0, Qt::AlignCenter);
    verticalLayout1->addWidget(gioca, 0, Qt::AlignCenter);
    verticalLayout1->addWidget(storico, 0, Qt::AlignCenter);

    connect(gioca, SIGNAL (released()),this, SLOT (handleButton()));
    connect(storico, SIGNAL (released()),this, SLOT (handleButton()));

    setLayout(verticalLayout1);
}

void ScegliApplicativo::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if(button->objectName()=="gioca"){
        emit signalBottone("gioca");
    } else if(button->objectName()=="storico"){
        emit signalBottone("storico");
    }
}
