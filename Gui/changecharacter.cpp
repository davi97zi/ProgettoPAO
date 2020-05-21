#include "changecharacter.h"
#include "match.h"

#include <QSizePolicy>

ChangeCharacter::ChangeCharacter(QWidget* parent):
    QWidget(parent)
{

     changeCharacterWindow = new QWidget();

     //il grid è il contenitore piu esterno
     gridLayout1 = new QGridLayout(changeCharacterWindow);

     //titolo della window
     titolo = new QLabel("Cambia il personaggio", dynamic_cast<QWidget*>(gridLayout1));
     titolo->setAlignment(Qt::AlignTop);
     titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
     //-------------------------------------------------

     //vertical1 esterno
     vlEx = new QVBoxLayout();

     //creo un QVBoxLayout per ogni personaggio all'interno del contenitore
     QVBoxLayout* v = new QVBoxLayout();

     //mi serve dopo per definire il numero di righe
     int i=0;

     //scorro il contenitore
     for(){
         labelNome = new QLabel("Nome: " + contenitore->personaggio->getNome()); //something like that
         labelTipo = new QLabel("Tipo: " + contenitore->personaggio->getTipo()); //something like that
         scegli = new QPushButton("Scegli");
         v->addWidget(labelNome);
         v->addWidget(labelTipo);
         v->addWidget(scegli);
         vlEx->addLayout(v);
     }

     gridLayout1->addWidget(titolo);
     gridLayout1->addLayout(vlEx, i, 2); //qui utilizzo 'i' del for

     //-------------------------------------------------

     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     //-------------------------------------------------

     changeCharacterWindow->setLayout(vlEx);
     changeCharacterWindow->show();
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
