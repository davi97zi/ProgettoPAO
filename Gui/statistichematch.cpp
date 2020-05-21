#include "statistichematch.h"
#include "mago.h"
#include "artificiere.h"
#include <QSizePolicy>

#include "changecharacter.h"

StatisticheMatch::StatisticheMatch(QWidget* parent): QWidget(parent) {
    stats = new QGridLayout();

    stats->setVerticalSpacing(6);
    stats->setHorizontalSpacing(6);
}

//sistemare funzioni con controller

QLayout* StatisticheMatch::statsMostro(){
    titolo = new QLabel("STATISTICHE");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    health = new QLabel("Health: " + getHealth());
    health->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttack = new QLabel("BaseAttack: " + getBaseAttack());
    baseAttack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    armor = new QLabel("Armor: " + getArmor());
    armor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    mana = new QLabel("Mana: 0");
    mana->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stats->addLayout(statsMostro(), 3, 2);
    return stats;
}

QLayout* StatisticheMatch::statsPersonaggio(){
    titolo = new QLabel("STATISTICHE");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    health = new QLabel("Health: " + getHealth());
    health->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttack = new QLabel("BaseAttack: " + getBaseAttack());
    baseAttack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    armor = new QLabel("Armor: " + getArmor());
    armor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    //controller
    if(p->getTipoPersonaggio() == "Mago"){
        Mago* m;
        auto pMana = QString::number(m->getMana());

        mana = new QLabel("Mana: " + pMana);
    } else if(p->getTipoPersonaggio() == "Artificiere"){
        Artificiere* a;
        auto pMana = QString::number(a->getMana());

        mana = new QLabel("Mana: " + pMana);
    } else
        mana = new QLabel("Mana: 0");


    cambiaPersonaggio = new QPushButton("Cambia personaggio");
    cambiaPersonaggio->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    connect(cambiaPersonaggio, SIGNAL (released()),this, SLOT (handleButton()));

    stats->addWidget(titolo);
    stats->addWidget(health);
    stats->addWidget(baseAttack);
    stats->addWidget(armor);
    stats->addWidget(mana);
    stats->addWidget(cambiaPersonaggio);

    stats->addLayout(statsPersonaggio(), 4, 2);
    return stats;
}

void StatisticheMatch::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
        if(button->objectName() == "cambiaPersonaggio"){
            ChangeCharacter* cc;
            cc->show();
        }
}
