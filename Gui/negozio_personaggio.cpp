#include "negozio_personaggio.h"


//verosimile che controller si occupi di passare questi dati? y, in this way? idk we will see
Negozio_personaggio::Negozio_personaggio(int i, QString n, QString t, int l, int p, QWidget *parent) : QWidget(parent){
    //salva l'id
    //id= i;

    //popola i label
    nome= new QLabel("Nome: " + n);
    tipo= new QLabel("Tipo: " + t);
    livello= new QLabel("Livello: " + QString::number(l));
    prezzo= new QLabel("Prezzo: " + QString::number(p));

    //crea il bottone
    assolda= new QPushButton("Assolda");
    //gli dò un objName
    assolda->setObjectName(QString::number(i));

    //conect: quale bottone ho cliccato?= quale personaggio ho scelto
    connect(assolda, SIGNAL(released()), this, SLOT(comunicaPersonaggio()));

    //crea il groupbox
    QGroupBox * scheda= new QGroupBox("Personaggio" + QString::number(i+1));

    //inserisci tutto in layout
    QVBoxLayout * groupLay= new QVBoxLayout();
    groupLay->addWidget(nome, 0, Qt::AlignCenter);
    groupLay->addWidget(tipo, 0, Qt::AlignCenter);
    groupLay->addWidget(livello, 0, Qt::AlignCenter);
    groupLay->addWidget(prezzo, 0, Qt::AlignCenter);
    groupLay->addWidget(assolda, 0, Qt::AlignCenter);

    //all in the groupbox now!
    groupLay->addStretch(1);
    scheda->setLayout(groupLay);

    //... i guess i put in the widget wt a new layout?
    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(scheda);
    setLayout(lay);
    //qui andranno i connect x far funzionare il tutto

}

void Negozio_personaggio::comunicaPersonaggio(){
    qDebug() << "1) è partito il comunicaPersonaggio() da Negozio_personaggio";
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    emit personaggioAcquistato(button->objectName().toInt());
}
