#include "statistichematchmostro.h"
#include "mago.h"
#include "artificiere.h"
#include <QSizePolicy>

#include "changecharacter.h"

StatisticheMatchMostro::StatisticheMatchMostro(int h, int ba, int a, QString n, int l, int exp, QWidget* parent): QWidget(parent) {
    tot = new QHBoxLayout;

    info = new QGridLayout();

    ex = new QHBoxLayout();

    experience = new QLabel("Experience: " +  QString::number(exp));

    stats = new QGridLayout();

    titolo = new QLabel("STATISTICHE");
    titolo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    health = new QLabel("Health: " + QString::number(h));
    health->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    armor = new QLabel("Armor: " + QString::number(a));
    armor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttack = new QLabel("BaseAttack: " + QString::number(ba));
    baseAttack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stats->addWidget(titolo, 0, 0, 1, 2, Qt::AlignCenter);
    stats->addWidget(health, 1, 0, Qt::AlignLeft);
    stats->addWidget(baseAttack, 1, 1, Qt::AlignRight);
    stats->addWidget(armor, 2, 0, Qt::AlignLeft);

    nomeMostro = new QLabel("Mostro: " + n);
    livelloMostro = new QLabel("Livello: " + QString::number(l));

    ex->addWidget(experience, 0, Qt::AlignCenter);

    info->addWidget(nomeMostro, 0, 0, Qt::AlignCenter);
    info->addWidget(livelloMostro , 1, 0, Qt::AlignCenter);

    tot->addLayout(stats);
    tot->addLayout(ex);
    tot->addLayout(info);

    setLayout(tot);
}

void StatisticheMatchMostro::setHealth(int h){
    health->setText("Health: " + QString::number(h));
    health->setStyleSheet("QLabel{color: red}");
}
