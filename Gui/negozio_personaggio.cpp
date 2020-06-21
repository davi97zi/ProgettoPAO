#include "negozio_personaggio.h"


Negozio_personaggio::Negozio_personaggio(int i, QString n, QString t, int l, int p, QWidget *parent) : QWidget(parent){
    //popola i label
    nome= new QLabel("Nome: " + n);
    tipo= new QLabel("Tipo: " + t);
    livello= new QLabel("Livello: " + QString::number(l));
    prezzo= new QLabel("Prezzo: " + QString::number(p));

    assolda= new QPushButton("Assolda");
    assolda->setObjectName(QString::number(i));

    //conect: quale bottone ho cliccato?= quale personaggio ho scelto
    connect(assolda, SIGNAL(released()), this, SLOT(comunicaPersonaggio()));

    //crea il groupbox
    QGroupBox * scheda= new QGroupBox("Personaggio" + QString::number(i+1));


    QVBoxLayout * groupLay= new QVBoxLayout();
    groupLay->addWidget(nome, 0, Qt::AlignCenter);
    groupLay->addWidget(tipo, 0, Qt::AlignCenter);
    groupLay->addWidget(livello, 0, Qt::AlignCenter);
    groupLay->addWidget(prezzo, 0, Qt::AlignCenter);
    groupLay->addWidget(assolda, 0, Qt::AlignCenter);

    groupLay->addStretch(1);
    scheda->setLayout(groupLay);

    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(scheda);
    setLayout(lay);
}

void Negozio_personaggio::comunicaPersonaggio(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    emit personaggioAcquistato(button->objectName().toInt());
}
