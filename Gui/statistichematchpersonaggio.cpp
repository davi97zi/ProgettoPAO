#include "statistichematchpersonaggio.h"
#include "mago.h"
#include "artificiere.h"
#include "abilita_personaggio_match.h"
#include <QSizePolicy>
#include <QDebug>

#include "changecharacter.h"

StatisticheMatchPersonaggio::StatisticheMatchPersonaggio(int h, int ba, int a, QString n, int l, int m, QWidget* parent): QWidget(parent) {
    tot = new QHBoxLayout;

    info = new QGridLayout();

    stats = new QGridLayout();

    titolo = new QLabel("STATISTICHE");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    health = new QLabel("Health: " + QString::number(h));
    health->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttack = new QLabel("BaseAttack: " + QString::number(ba));
    baseAttack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    armor = new QLabel("Armor: " + QString::number(a));
    armor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    mana = new QLabel("Mana: " + QString::number(m));
    mana->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    cambiaPersonaggio = new QPushButton("Cambia personaggio");
    cambiaPersonaggio->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    cambiaPersonaggio->setStyleSheet("QPushButton{border-style: outset; border-width: 1px;border-radius: 10px;border-color: black; min-width: 10em;padding: 6px;}"
                                     "QPushButton:pressed {background-color: beige; border-style: inset;}");
    cambiaPersonaggio->setObjectName("cambiaPersonaggio");
    connect(cambiaPersonaggio, SIGNAL (released()),this, SLOT (handleButton()));

    stats->addWidget(titolo, 0, 0, 1, 2, Qt::AlignCenter);
    stats->addWidget(health, 1, 0, Qt::AlignLeft);
    stats->addWidget(baseAttack, 1, 1, Qt::AlignRight);
    stats->addWidget(armor, 2, 0, Qt::AlignLeft);
    stats->addWidget(mana, 2, 1, Qt::AlignRight);
    stats->addWidget(cambiaPersonaggio, 3, 0, 1, 2, Qt::AlignCenter);

    QLabel* personaggio = new QLabel("Personaggio: " + n);
    QLabel* livelloP = new QLabel("Livello: " + QString::number(l));

    info->addWidget(personaggio, 0, 0, Qt::AlignCenter);
    info->addWidget(livelloP , 1, 0, Qt::AlignCenter);

    tot->addLayout(info);
    tot->addLayout(getAbilities());
    tot->addLayout(stats);

    setLayout(tot);
}

/*controller
if(p->getTipoPersonaggio() == "Mago"){
    Mago* m;
    auto pMana = QString::number(m->getMana());

    mana = new QLabel("Mana: " + pMana);
} else if(p->getTipoPersonaggio() == "Artificiere"){
    Artificiere* a;
    auto pMana = QString::number(a->getMana());

    mana = new QLabel("Mana: " + pMana);
} else
    mana = new QLabel("Mana: 0");*/

QGridLayout* StatisticheMatchPersonaggio::getAbilities(){
    QGridLayout* abilita = new QGridLayout();
    abilita->setVerticalSpacing(6);
    abilita->setHorizontalSpacing(6);

    titolo = new QLabel("ABILITÀ");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    baseAttackBtn = new QPushButton("BaseAttack");
    baseAttackBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    baseAttackBtn->setObjectName("baseAttack");

    abilita1 = new QPushButton("Abilità1");
    abilita1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    abilita1->setObjectName("abilita1");

    abilita2 = new QPushButton("Abilità2");
    abilita2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    abilita2->setObjectName("abilita2");

    abilita3 = new QPushButton("Abilità3");
    abilita3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    abilita3->setObjectName("abilita3");

    connect(baseAttackBtn, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita1, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita2, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita3, SIGNAL (released()),this, SLOT (handleButton()));

    abilita->addWidget(titolo, 0 , 0, 1, 2, Qt::AlignCenter);//prima riga
    abilita->addWidget(baseAttackBtn, 1, 0, Qt::AlignLeft);
    abilita->addWidget(abilita1, 1, 1, Qt::AlignRight);
    abilita->addWidget(abilita2, 2, 0, Qt::AlignLeft);
    abilita->addWidget(abilita3, 2, 1, Qt::AlignRight);

    return abilita;
}

void StatisticheMatchPersonaggio::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    if(button->objectName() != "cambiaPersonaggio"){
        emit eseguiAbilita(button->objectName());
    }else
        emit cambiaPersonaggioBtn();
}

void StatisticheMatchPersonaggio::setArmor(int arm){
    armor->setText("Armor: " + QString::number(arm));
}

void StatisticheMatchPersonaggio::setHealth(int hp){
    health->setText("Health: " + QString::number(hp));
}



