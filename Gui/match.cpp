#include "match.h"

Match::Match(QWidget* parent): QWidget(parent){
    window = new QWidget();

    contenitore = new QVBoxLayout();

    //gestite dal controller
    turno = new QLabel("Turno: " + QString::number(getTurno()));
    coins = new QLabel("Monete: " + QString::number(getMonete()));
    turno->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    coins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    layoutMostro = new QGridLayout();
    layoutPersonaggio = new QGridLayout();

    InfoMatch* info = nullptr;
    StatisticheMatch* stats = nullptr;
    AbilitaPersonaggioMatch* abilita = nullptr;

    //Immagine del mostro

    QVBoxLayout* imageVertical = new QVBoxLayout();

    QImage* myImage;
    myImage->load("immagine.png"); //path immagine

    QLabel* img;
    img->setPixmap(QPixmap::fromImage(*myImage));
    //img->resize();
    //img->show();

    imageVertical->addWidget(img);

    layoutMostro->addLayout(stats->statsMostro(),1,1);//1,1 perche il numero effettivo righe e colonne si trova in statisticheMatch
    layoutMostro->addLayout(imageVertical, 1, 1);
    layoutMostro->addLayout(info->setLayoutMostro(), 2, 1);

    layoutPersonaggio->addLayout(info->setLayoutPersonaggio(), 2,1);
    layoutPersonaggio->addLayout(dynamic_cast<QLayout*>(abilita), 1,1);
    layoutPersonaggio->addLayout(stats->statsPersonaggio(), 1, 1); //1,1 perche il numero effettivo righe e colonne si trova in statisticheMatch

    contenitore->addWidget(turno);
    contenitore->addWidget(coins);
    contenitore->addLayout(layoutMostro);
    contenitore->addLayout(layoutPersonaggio);

    window->setLayout(contenitore);
    window->show();
}
