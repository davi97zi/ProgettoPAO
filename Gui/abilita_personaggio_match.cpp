#include "abilita_personaggio_match.h"

AbilitaPersonaggioMatch::AbilitaPersonaggioMatch(QWidget* parent): QWidget(parent){
    abilita = new QGridLayout();
    abilita->setVerticalSpacing(6);
    abilita->setHorizontalSpacing(6);

    titolo = new QLabel("ABILITÀ");
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); //horizontal: preferred, vertical: fixed
    titolo->setAlignment(Qt::AlignCenter);

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
    abilita->addWidget(baseAttack, 1, 0, Qt::AlignLeft);
    abilita->addWidget(abilita1, 1, 1, Qt::AlignRight);
    abilita->addWidget(abilita2, 2, 0, Qt::AlignLeft);
    abilita->addWidget(abilita3, 2, 1, Qt::AlignRight);

    setLayout(abilita);
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
