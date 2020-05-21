#include "match.h"

Match::Match(QWidget* parent): QWidget(parent){
    window = new QWidget();

    contenitore = new QVBoxLayout();

    //gestite dal controller
    turno = new QLabel("Turno: " + getTurno());
    coins = new QLabel("Monete: " + getMonete());
    turno->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    coins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    layoutMostro = new QGridLayout();
    layoutPersonaggio = new QGridLayout();

    InfoMatch* info = nullptr;
    StatisticheMatch* stats = nullptr;
    AbilitaPersonaggioMatch* abilita = nullptr;

    QLabel* img = new QLabel("Qui ci va un immagine del mostro");

    //da ricontrolloare: io qui rimetto il numero di righe e colonne che ho pero gia messo nelle classi interne
    layoutMostro->addLayout(stats->statsMostro(),3,2);
    layoutMostro->addWidget(img);
    layoutMostro->addLayout(info->setLayoutMostro(), 2, 1);

    //da ricontrolloare: io qui rimetto il numero di righe e colonne che ho pero gia messo nelle classi interne
    layoutPersonaggio->addLayout(info->setLayoutPersonaggio(), 2 ,1);
    layoutPersonaggio->addLayout(dynamic_cast<QLayout*>(abilita), 3, 2);
    layoutPersonaggio->addLayout(stats->statsPersonaggio(), 4, 2);

    contenitore->addWidget(turno);
    contenitore->addWidget(coins);
    contenitore->addLayout(layoutMostro);
    contenitore->addLayout(layoutPersonaggio);

    window->setLayout(contenitore);
    window->show();
}
