#include "negozio_personaggio.h"
#include <QVBoxLayout>

//verosimile che controller si occupi di passare questi dati? y, in this way? idk we will see
Negozio_personaggio::Negozio_personaggio(int i, QString n, QString t, int l, int p, QWidget *parent) : QWidget(parent){
    //salva l'id
    id= i;

    //popola i label
    nome= new QLabel(n);
    tipo= new QLabel(t);
    livello= new QLabel(QString::number(l));
    prezzo= new QLabel(QString::number(p));

    //inserisci tutto in un layout
    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(nome);
    lay->addWidget(tipo);
    lay->addWidget(livello);
    lay->addWidget(prezzo);

    //qui andranno i connect x far funzionare il tutto

    //set layout
    setLayout(lay);
}
