#include "statistichepersonaggio.h"

StatistichePersonaggio::StatistichePersonaggio(QWidget* parent, const QString& n, const QString& t, const QString& l, const QString& p): QWidget(parent){
    statistiche = new QWidget();

    vertical = new QVBoxLayout();

    horizontal = new QHBoxLayout();

    nome = new QLabel(n, statistiche);
    tipologia = new QLabel(t, statistiche);
    livello = new QLabel(l, statistiche);
    prezzo = new QLabel(p, statistiche);

    horizontal->addWidget(nome, Qt::AlignTop);
    horizontal->addWidget(livello, Qt::AlignTop);
    horizontal->addWidget(tipologia, Qt::AlignCenter);
    horizontal->addWidget(prezzo, Qt::AlignBottom);

    vertical->addLayout(horizontal);

    statistiche->setLayout(vertical);
    //statistiche->show();
}
