#include "match.h"
#include <QDebug>


Match::Match(StatisticheMatchMostro* smm, StatisticheMatchPersonaggio* smp, int t, int m, QWidget* parent): QWidget(parent){
    contenitore = new QVBoxLayout();

    //gestite dal controller
    turno = new QLabel("Turno: " + QString::number(t));
    turno->setStyleSheet("QLabel{border-radius: 25px; font: bold 14px;}");
    coins = new QLabel("Monete: " + QString::number(m));
    coins->setStyleSheet("QLabel{border-radius: 25px; color: blue;}");
    turno->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    coins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    layoutMostro = new QGridLayout();
    layoutPersonaggio = new QGridLayout();

    statsP = smp;
    statsM = smm;

    connect(statsP, SIGNAL(eseguiAbilita(QString)), this, SLOT(sendAction(QString)));

    contenitore->addWidget(turno, 0, Qt::AlignCenter);
    contenitore->addWidget(coins, 0, Qt::AlignCenter);
    contenitore->addWidget(statsM);
    contenitore->addWidget(statsP);

    setLayout(contenitore);
}

void Match::sendAction(QString a){
    emit eseguiAbilitaP(a);
}
