#include "negozio_widget.h"

Negozio_widget::Negozio_widget(std::vector<XmlItem> assoldabili, int m, bool inizio, QWidget *parent) : QWidget(parent), monete(m){
    for(int i=0; i<3; i++){
        setPersonaggioNegozio(i,
            assoldabili[static_cast<unsigned int>(i)].getNome(),
            assoldabili[static_cast<unsigned int>(i)].getTipo(),
            static_cast<int>(assoldabili[static_cast<unsigned int>(i)].getLivello()),
            assoldabili[static_cast<unsigned int>(i)].getPrezzo());
    }

    connect(primo, SIGNAL(personaggioAcquistato(int)), this, SLOT(stampaDaNegozio(int)));
    connect(secondo, SIGNAL(personaggioAcquistato(int)), this, SLOT(stampaDaNegozio(int)));
    connect(terzo, SIGNAL(personaggioAcquistato(int)), this, SLOT(stampaDaNegozio(int)));

    //creo indicazione dei soldi posseduti
    soldi= new QLabel(QString::number(m)+" soldi disponibili");

    //bottone di proseguimento-> premi per lasciare la taverna
    prosegui= new QPushButton("prosegui");
    connect(prosegui, SIGNAL(released()), this, SLOT(proseguiMatch()));
    QLabel * titolo= new QLabel("Taverna");

    QLabel * descrizione= new QLabel("Ben arrivato alla taverna, qui puoi assoldare avventurieri per il tuo team. "
                                     "\nGuardati attorno e scegli un compagno di avventure.\n hai: ");

    titolo->setObjectName("titolo");
    descrizione->setObjectName("descrizione");
    titolo->setStyleSheet("QLabel#titolo{color:blue;}");

    descrizione->setStyleSheet("QLabel#descrizione{text-align: center;"
                               "margin: 0.5em;"
                               "color:red;}");

    //add to layout for the 3 personaggi
    QHBoxLayout * personaggioLay= new QHBoxLayout();
    personaggioLay->addWidget(primo);
    personaggioLay->addWidget(secondo);
    personaggioLay->addWidget(terzo);

    //add to the total layout
    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(titolo, 0, Qt::AlignTop | Qt::AlignHCenter);
    lay->addWidget(descrizione, 0, Qt::AlignCenter);
    lay->addWidget(soldi, 0, Qt::AlignTop | Qt::AlignHCenter);
    lay->addLayout(personaggioLay);
    if(!inizio){ //visibile solo se siamo DENTRO UNA PARTITA, non all'inizio
        lay->addWidget(prosegui, 0, Qt::AlignCenter);
    }

    setLayout(lay);
}

void Negozio_widget::setPersonaggioNegozio(int quale, QString n, QString t, int l, int p){
    switch(quale){
        case 0:
            primo= new Negozio_personaggio(quale, n, t, l, p, this);
        break;
        case 1:
            secondo= new Negozio_personaggio(quale, n, t, l, p, this);
        break;
        case 2:
            terzo= new Negozio_personaggio(quale, n, t, l, p, this);
        break;
    }
}

void Negozio_widget::stampaDaNegozio(int i){
    emit personaggioAcquistato(i);
}

void Negozio_widget::proseguiMatch(){
    emit newMatch();
}
