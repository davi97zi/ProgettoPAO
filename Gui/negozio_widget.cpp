#include "negozio_widget.h"
#include "QHBoxLayout"
#include "QVBoxLayout"

Negozio_widget::Negozio_widget(QWidget *parent) : QWidget(parent){
    //per popolare dovrei -> recuperare il LIVELLO/BATTAGLIA

    //chiedere al controller-> dammi i tre personaggi che posso scegliere in base al livello in cui sono

    //usa il risultato per effettuare il set dei 3 negozio_personaggio *
    setPrimo(1, "nome1", "tipo1", 1, 1);
    setSecondo(2, "nome2", "tipo2", 1, 1);
    setTerzo(3, "nome3", "tipo3", 1, 2);

    //bottone di proseguimento-> premi per lasciare la taverna
    prosegui= new QPushButton("prosegui");
    //set titolo in qlabel NB to do on the WINDOW AS WELL!
    QLabel * titolo= new QLabel("Taverna");
    //descrivi la pagina
    QLabel * descrizione= new QLabel("Ben arrivato alla taverna, qui puoi assoldare avventurieri per il tuo team. "
                                     "\nGuardati attorno e scegli un compagno di avventure");
    //


    //set cssNames
    titolo->setObjectName("titolo");
    descrizione->setObjectName("descrizione");
    //prova a vedere un paio di effetti
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
    lay->addLayout(personaggioLay);
    lay->addWidget(prosegui, 0, Qt::AlignCenter);

    //imposta il layout principale
    setLayout(lay);
}

void Negozio_widget::setPrimo(int i, QString n, QString t, int l, int p){
    primo= new Negozio_personaggio(i, n, t, l, p, this);
}

void Negozio_widget::setSecondo(int i, QString n, QString t, int l, int p){
    secondo= new Negozio_personaggio(i, n, t, l, p, this);
}

void Negozio_widget::setTerzo(int i, QString n, QString t, int l, int p){
    terzo= new Negozio_personaggio(i, n, t, l, p, this);

}
