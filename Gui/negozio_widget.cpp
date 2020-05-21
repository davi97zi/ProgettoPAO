#include "negozio_widget.h"
#include "QHBoxLayout"
Negozio_widget::Negozio_widget(QWidget *parent) : QWidget(parent){
    //per popolare dovrei -> recuperare il LIVELLO/BATTAGLIA

    //chiedere al controller-> dammi i tre personaggi che posso scegliere in base al livello in cui sono

    //usa il risultato per effettuare il set dei 3 negozio_personaggio *
    setPrimo(1, "nome1", "tipo1", 1, 1);
    setSecondo(2, "nome2", "tipo2", 1, 1);
    setTerzo(3, "nome3", "tipo3", 1, 2);

    //add to layout
    QHBoxLayout * lay= new QHBoxLayout();
    lay->addWidget(primo);
    lay->addWidget(secondo);
    lay->addWidget(terzo);

    //imposta il layout
    setLayout(lay);
}

void Negozio_widget::setPrimo(int i, QString n, QString t, int l, int p){
    primo= new Negozio_personaggio(i, n, t, p, this);
}

void Negozio_widget::setSecondo(int i, QString n, QString t, int l, int p){
    secondo= new Negozio_personaggio(i, n, t, p, this);
}

void Negozio_widget::setTerzo(int i, QString n, QString t, int l, int p){
    terzo= new Negozio_personaggio(i, n, t, p, this);

}
