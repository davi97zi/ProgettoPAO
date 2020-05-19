#include "changecharacter.h"
#include "match.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSizePolicy>

ChangeCharacter::ChangeCharacter(QWidget* parent):
    QWidget(parent)
{

     QWidget* changeCharacterWindow = new QWidget;

     //il grid è il contenitore piu esterno
     QGridLayout* gridLayout1 = new QGridLayout(changeCharacterWindow);

     //titolo della window
     QLabel* label = new QLabel("Cambia il personaggio", dynamic_cast<QWidget*>(gridLayout1));

     //-------------------------------------------------

     //vertical1 esterno
     QVBoxLayout* vl1 = new QVBoxLayout();

     QVBoxLayout* vl1interno = new QVBoxLayout();
     QVBoxLayout* vl2interno = new QVBoxLayout();
     QVBoxLayout* vl3interno = new QVBoxLayout();
     QVBoxLayout* vl4interno = new QVBoxLayout();
     QVBoxLayout* vl5interno = new QVBoxLayout();

     //-------------------------------------------------

     //label dei vertical e button

     /*
         QLabel* label1 = new QLabel("Nome", dynamic_cast<QWidget*>(vl1interno));
         QLabel* label2 = new QLabel("Tipologia", dynamic_cast<QWidget*>(vl1interno));
         QPushButton* scegli = new QPushButton("Scegli", dynamic_cast<QWidget*>(vl1interno));
     */

     QLabel* label1 = new QLabel("Nome");
     QLabel* label2 = new QLabel("Tipologia");
     QPushButton* scegli = new QPushButton("Scegli");

     //-------------------------------------------------

     vl1interno->addWidget(label1, 0, Qt::AlignTop);
     vl1interno->addWidget(label2, 0, Qt::AlignCenter);
     vl1interno->addWidget(scegli, 0, Qt::AlignBottom);

     vl1->addLayout(vl1interno);
     //-------------------------------------------------

     vl2interno->addWidget(label1, 0, Qt::AlignTop);
     vl2interno->addWidget(label2, 0, Qt::AlignCenter);
     vl2interno->addWidget(scegli, 0, Qt::AlignBottom);

     vl1->addLayout(vl2interno);

     //-------------------------------------------------

     vl3interno->addWidget(label1, 0, Qt::AlignTop);
     vl3interno->addWidget(label2, 0, Qt::AlignCenter);
     vl3interno->addWidget(scegli, 0, Qt::AlignBottom);

     vl1->addLayout(vl3interno);

     //-------------------------------------------------

     vl4interno->addWidget(label1, 0, Qt::AlignTop);
     vl4interno->addWidget(label2, 0, Qt::AlignCenter);
     vl4interno->addWidget(scegli, 0, Qt::AlignBottom);

     vl1->addLayout(vl4interno);

     //-------------------------------------------------

     vl5interno->addWidget(label1, 0, Qt::AlignTop);
     vl5interno->addWidget(label2, 0, Qt::AlignCenter);
     vl5interno->addWidget(scegli, 0, Qt::AlignBottom);

     vl1->addLayout(vl5interno);

     //-------------------------------------------------

     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     //-------------------------------------------------

     changeCharacterWindow->setLayout(vl1);
     changeCharacterWindow->show();
}

void ChangeCharacter::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    if(button->objectName() == "scegli"){   //ritorna in match, ed aggiunge il personaggio al container
        //aggiungi il personaggio al container

        //torna nella schermata della partita
        Match* m;
        m->show();
    }
}
