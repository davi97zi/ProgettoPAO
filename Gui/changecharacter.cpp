#include "changecharacter.h"
#include "match.h"

#include <QSizePolicy>

ChangeCharacter::ChangeCharacter(QWidget* parent):
    QWidget(parent)
{

    // changeCharacterWindow = new QWidget();

    QVBoxLayout* vE = new QVBoxLayout;

     //il grid è il contenitore piu esterno
     gridLayout1 = new QGridLayout();

     //titolo della window
     titolo = new QLabel("Cambia il personaggio");
     titolo->setAlignment(Qt::AlignTop);
     titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
     //-------------------------------------------------

     //vertical1 esterno
     vlEx = new QVBoxLayout();

     //creo un QVBoxLayout per ogni personaggio all'interno del contenitore
     QVBoxLayout* v = new QVBoxLayout();

     for(int i=0; i<3; i++){
         labelNome = new QLabel("Nome: " + QString::number(i)); //something like that
         labelTipo = new QLabel("Tipo: " + QString::number(i)); //something like that
         scegli = new QPushButton("Scegli");
         v->addWidget(labelNome);
         v->addWidget(labelTipo);
         v->addWidget(scegli);
         vlEx->addLayout(v);
     }


     vE->addWidget(titolo, 0 , Qt::AlignCenter);
     vE->addLayout(vlEx); //qui utilizzo 'i' del for

     //-------------------------------------------------

     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     //-------------------------------------------------

     setLayout(vE);
    // changeCharacterWindow->show();
}

void ChangeCharacter::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    if(button->objectName() == "scegli"){   //ritorna in match, ed aggiunge il personaggio al container
        //aggiungi il personaggio al container

        //torna nella schermata della partita
        Match* m;
        m->show();

        changeCharacterWindow->close();
    }
}
