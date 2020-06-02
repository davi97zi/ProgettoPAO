#include "match.h"
#include "statistichematchmostro.h"
#include "statistichematchpersonaggio.h"

Match::Match(QWidget* parent): QWidget(parent){
    contenitore = new QVBoxLayout();

    //gestite dal controller
    turno = new QLabel("Turno: " + QString::number(1));
    turno->setStyleSheet("QLabel{border-radius: 25px; font: bold 14px;}");
    coins = new QLabel("Monete: " + QString::number(10));
    coins->setStyleSheet("QLabel{border-radius: 25px; color: blue;}");
    turno->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    coins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    layoutMostro = new QGridLayout();
    layoutPersonaggio = new QGridLayout();

    StatisticheMatchPersonaggio* statsP = new StatisticheMatchPersonaggio;
    StatisticheMatchMostro* statsM = new StatisticheMatchMostro;

    contenitore->addWidget(turno, 0, Qt::AlignCenter);
    contenitore->addWidget(coins, 0, Qt::AlignCenter);
    contenitore->addWidget(statsM);
    contenitore->addWidget(statsP);

    setLayout(contenitore);
}
