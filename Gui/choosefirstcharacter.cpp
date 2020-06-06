#include "choosefirstcharacter.h"
#include "ui_choosefirstcharacter.h"
#include "match.h"

ChooseFirstCharacter::ChooseFirstCharacter(QWidget* parent): QWidget(parent){
     //chooseCharacterWindow = new QWidget();

     verticalLayout1 = new QVBoxLayout();
     titolo = new QLabel("Scegli il tuo primo personaggio");

     QHBoxLayout* horizontalLayout1 = new QHBoxLayout;     


     spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

     horizontalLayout1->addLayout(personaggio1());
     horizontalLayout1->addLayout(personaggio2());
     horizontalLayout1->addLayout(personaggio3());

     verticalLayout1->addWidget(titolo,0, Qt::AlignCenter);
     verticalLayout1->addLayout(horizontalLayout1);

     //gridLayout1->addLayout(verticalLayout1);

     //connessione buttons -> gestiti da handleButton() (virtual)
     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     setLayout(verticalLayout1);
     //chooseCharacterWindow->show();
}

//I primi 3 personaggi sono sempre uguali

QVBoxLayout* ChooseFirstCharacter::personaggio1(){
    QVBoxLayout* verticalLayout = new QVBoxLayout;

    nome = new QLabel("Nome: Yasuo");
    tipo = new QLabel("Tipo: Soldato");
    scegli = new QPushButton("Scegli");

    verticalLayout->addWidget(nome,0,Qt::AlignTop);
    verticalLayout->addWidget(tipo,0,Qt::AlignCenter);
    verticalLayout->addWidget(scegli,0,Qt::AlignBottom);
    verticalLayout->addItem(spacer);

    return verticalLayout;
}

QVBoxLayout* ChooseFirstCharacter::personaggio2(){
    QVBoxLayout* verticalLayout = new QVBoxLayout;

    nome = new QLabel("Nome: Nami");
    tipo = new QLabel("Tipo: Guaritore");

    scegli = new QPushButton("Scegli");
    verticalLayout->addWidget(nome,0,Qt::AlignTop);
    verticalLayout->addWidget(tipo,0,Qt::AlignCenter);
    verticalLayout->addWidget(scegli,0,Qt::AlignBottom);
    verticalLayout->addItem(spacer);

    return verticalLayout;
}

QVBoxLayout* ChooseFirstCharacter::personaggio3(){
    QVBoxLayout* verticalLayout = new QVBoxLayout;

    nome = new QLabel("Nome: Malphite");
    tipo = new QLabel("Tipo: Tank");
    scegli = new QPushButton("Scegli");

    verticalLayout->addWidget(nome,0,Qt::AlignTop);
    verticalLayout->addWidget(tipo,0,Qt::AlignCenter);
    verticalLayout->addWidget(scegli,0,Qt::AlignBottom);
    verticalLayout->addItem(spacer);

    return verticalLayout;
}

void ChooseFirstCharacter::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if(button->objectName() == "Scegli"){
        //salvare personaggio nel container e di conseguenza nel file
        Match* m;
        m->show();
        chooseCharacterWindow->close();
    }
}
