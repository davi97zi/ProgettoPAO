#include "choosefirstcharacter.h"
#include "ui_choosefirstcharacter.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSizePolicy>

ChooseFirstCharacter::ChooseFirstCharacter(QWidget* parent):
    QWidget(parent)
{

     QWidget* chooseCharacterWindow = new QWidget;

     //il grid è il contenitore piu esterno
     //QGridLayout* gridLayout1 = new QGridLayout(chooseCharacterWindow);

     QVBoxLayout* verticalLayout1 = new QVBoxLayout;
     QLabel* label1 = new QLabel("Scegli il tuo primo personaggio", chooseCharacterWindow);

     QHBoxLayout* horizontalLayout1 = new QHBoxLayout;

     //verticalLayout interni al horizontalLayout
     QVBoxLayout* verticalLayout2 = new QVBoxLayout;

     QLabel* nome = new QLabel("Nome");
     QLabel* tipo = new QLabel("Tipo");
     QLabel* personaggio = new QLabel("Descrizione");

     //un button e uno spacer per tutti e 3 i verticalLayout -> same per le label?
     QPushButton* scegli = new QPushButton("Scegli");
     QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

     verticalLayout2->addWidget(nome,0,Qt::AlignTop);
     verticalLayout2->addWidget(tipo,0,Qt::AlignCenter);
     verticalLayout2->addWidget(personaggio,0,Qt::AlignBottom);
     verticalLayout2->addWidget(scegli,0,Qt::AlignBottom);
     verticalLayout2->addItem(spacer);

     QVBoxLayout* verticalLayout3 = new QVBoxLayout;

     verticalLayout3->addWidget(nome,0,Qt::AlignTop);
     verticalLayout3->addWidget(tipo,0,Qt::AlignCenter);
     verticalLayout3->addWidget(personaggio,0,Qt::AlignBottom);
     verticalLayout3->addWidget(scegli,0,Qt::AlignBottom);
     verticalLayout3->addItem(spacer);

     QVBoxLayout* verticalLayout4 = new QVBoxLayout;

     verticalLayout4->addWidget(nome,0,Qt::AlignTop);
     verticalLayout4->addWidget(tipo,0,Qt::AlignCenter);
     verticalLayout4->addWidget(personaggio,0,Qt::AlignBottom);
     verticalLayout4->addWidget(scegli,0,Qt::AlignBottom);
     verticalLayout4->addItem(spacer);

     horizontalLayout1->addLayout(verticalLayout2);
     horizontalLayout1->addLayout(verticalLayout3);
     horizontalLayout1->addLayout(verticalLayout4);

     verticalLayout1->addWidget(label1,0, Qt::AlignTop);
     verticalLayout1->addLayout(horizontalLayout1);

     //gridLayout1->addLayout(verticalLayout1);

     //connessione buttons -> gestiti da handleButton() (virtual)
     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     chooseCharacterWindow->setLayout(verticalLayout1);
     chooseCharacterWindow->show();
}


ChooseFirstCharacter::~ChooseFirstCharacter()
{
    delete this;
}
