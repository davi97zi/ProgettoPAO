#include "info_match.h"

#include "../Interfacce/personaggio.h"
#include "../mostro.h"

InfoMatch::InfoMatch(QWidget* parent): QWidget(parent){

}

//info del personaggio
QVBoxLayout* InfoMatch::setLayoutPersonaggio(){
    personaggio = new QLabel("Personaggio: ciao");
    livelloPersonaggio = new QLabel("Livello:" + QString::number(2));

    vertical->addWidget(personaggio);
    vertical->addWidget(livelloPersonaggio);

    return vertical;
}

//info del mostro
QVBoxLayout* InfoMatch::setLayoutMostro(){
    mostro = new QLabel("Mostro: ciadaadado");
    livelloMostro = new QLabel("Livello:" + QString::number(4));

    vertical->addWidget(mostro);
    vertical->addWidget(livelloMostro);

    return vertical;
}

