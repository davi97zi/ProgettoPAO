#include "statistichematchmostro.h"
#include "mago.h"
#include "artificiere.h"
#include <QSizePolicy>

#include "changecharacter.h"

StatisticheMatchMostro::StatisticheMatchMostro(QWidget* parent): QWidget(parent) {
    tot = new QHBoxLayout;

    info = new QGridLayout();

    img = new QHBoxLayout();

    QLabel* acaso = new QLabel("Qui ci va un immagine");

    stats = new QGridLayout();

    titolo = new QLabel("STATISTICHE");
    titolo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    health = new QLabel("Health: " + QString::number(100));
    health->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttack = new QLabel("BaseAttack: " + QString::number(16));
    baseAttack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    armor = new QLabel("Armor: " + QString::number(20));
    armor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    mana = new QLabel("Mana: " + QString::number(0));
    mana->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stats->addWidget(titolo, 0, 0, 1, 2, Qt::AlignCenter);
    stats->addWidget(health, 1, 0, Qt::AlignLeft);
    stats->addWidget(baseAttack, 1, 1, Qt::AlignRight);
    stats->addWidget(armor, 2, 0, Qt::AlignLeft);
    stats->addWidget(mana, 2, 1, Qt::AlignRight);

    QLabel* mostro = new QLabel("Mostro: ciadaadado");
    QLabel* livelloMostro = new QLabel("Livello:" + QString::number(4));

    img->addWidget(acaso, 0, Qt::AlignCenter);

    info->addWidget(mostro, 0, Qt::AlignCenter);
    info->addWidget(livelloMostro , 1, Qt::AlignCenter);

    tot->addLayout(stats);
    tot->addLayout(img);
    tot->addLayout(info);

    setLayout(tot);
}

//Immagine del mostro
/*
QVBoxLayout* imageVertical = new QVBoxLayout();
QImage* myImage;
myImage->load("immagine.png"); //path immagine

QLabel* img;
img->setPixmap(QPixmap::fromImage(*myImage));
//img->resize();
//img->show();

imageVertical->addWidget(img);*/
