#include "abilita_personaggio_match.h"

AbilitaPersonaggioMatch::AbilitaPersonaggioMatch(QWidget* parent): QWidget(parent){
    titolo = new QLabel("ABILITÀ");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); //horizontal: preferred, vertical: fixed
    titolo->setAlignment(Qt::AlignCenter);

    abilitaEsterno = new QGridLayout();
    abilitaEsterno->setVerticalSpacing(6);
    abilitaEsterno->setHorizontalSpacing(6);

    abilita = new QGridLayout();
    abilita->setVerticalSpacing(6);
    abilita->setHorizontalSpacing(6);

    baseAttack = new QPushButton("BaseAttack");
    baseAttack->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    abilita1 = new QPushButton("Abilità1");
    abilita1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    abilita2 = new QPushButton("Abilità2");
    abilita2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    abilita3 = new QPushButton("Abilità3");
    abilita3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    connect(baseAttack, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita1, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita2, SIGNAL (released()),this, SLOT (handleButton()));
    connect(abilita3, SIGNAL (released()),this, SLOT (handleButton()));

    abilita->addWidget(titolo);//prima riga
    abilita->addWidget(baseAttack);
    abilita->addWidget(abilita1);
    abilita->addWidget(abilita2);
    abilita->addWidget(abilita3);

    abilitaEsterno->addLayout(abilita,3,2); //rows: 3, colums: 2
}

//funzione gestita dal controller
void AbilitaPersonaggioMatch::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    if(button->objectName() == "baseAttack"){
        //richiama funzione getBaseAttack() + receiveDmg() del mostro
    } else if(button->objectName() == "abilita1"){
        //richiama funzione abilita1() del personaggio + receiveDmg() del mostro
    } else if(button->objectName() == "abilita2"){
        //richiama funzione abilita2() del personaggio + receiveDmg() del mostro
    } else if(button->objectName() == "abilita3"){ //basterebbe solo else
        //richiama funzione abilita3() del personaggio + receiveDmg() del mostro
    }
}
