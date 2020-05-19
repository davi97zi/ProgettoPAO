#include "info_match.h"

#include "../Interfacce/personaggio.h"
#include "../mostro.h"

InfoMatch::InfoMatch(QWidget* parent): QWidget(parent){
    //da rimuovere
    Personaggio* p;
    Mostro* p;

    //da sistemare col controller
    personaggio = new QLabel(p->getNome());
    livelloPersonaggio = new QLabel(QString::number(p->getLevel()));

    mostro = new QLabel(m->getNome());
    livelloMostro = new QLabel(QString::number(m->getLevel()));
}

//info del personaggio
QLayout* InfoMatch::setLayoutPersonaggio(){
    vertical.addWidget(personaggio);
    vertical.addWidget(livelloPersonaggio);
}

//info del mostro
QLayout* InfoMatch::setLayoutMostro(){
    vertical.addWidget(mostro);
    vertical.addWidget(livelloMostro);
}
