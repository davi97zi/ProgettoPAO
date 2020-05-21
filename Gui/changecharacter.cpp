#include "changecharacter.h"
#include "match.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSizePolicy>

ChangeCharacter::ChangeCharacter(QWidget* parent):
    QWidget(parent)
{

     QWidget* changeCharacterWindow = new QWidget();

     //il grid è il contenitore piu esterno
     QGridLayout* gridLayout1 = new QGridLayout(changeCharacterWindow);

     //titolo della window
     QLabel* label = new QLabel("Cambia il personaggio", dynamic_cast<QWidget*>(gridLayout1));
     label->setAlignment(Qt::AlignTop);
     label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
     //-------------------------------------------------

     //vertical1 esterno
     QVBoxLayout* vl1 = new QVBoxLayout();

     /*QVBoxLayout* vl1interno = new QVBoxLayout();
     QVBoxLayout* vl2interno = new QVBoxLayout();
     QVBoxLayout* vl3interno = new QVBoxLayout();
     QVBoxLayout* vl4interno = new QVBoxLayout();
     QVBoxLayout* vl5interno = new QVBoxLayout();*/

     //-------------------------------------------------

     QLabel* label1 = new QLabel("Nome");
     QLabel* label2 = new QLabel("Tipologia");
     QPushButton* scegli = new QPushButton("Scegli");

     connect(scegli, SIGNAL (released()),this, SLOT (handleButton()));

     //-------------------------------------------------

     gridLayout1->addWidget(label);

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
