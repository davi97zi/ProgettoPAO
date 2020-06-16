#include "storicorow.h"
#include <QHBoxLayout>

StoricoRow::StoricoRow(QString d, QString l, QString num, QString m, QString r, QWidget *parent) :
    data(new QLabel(d)), livello(new QLabel(l)), numPers(new QLabel(num)), monete(new QLabel(m)), risultato(new QLabel(r)), info(new QPushButton("more info")), QWidget(parent){
    QHBoxLayout * lay= new QHBoxLayout;
    lay->addWidget(data);
    lay->addWidget(livello);
    lay->addWidget(numPers);
    lay->addWidget(monete);
    lay->addWidget(risultato);
    lay->addWidget(info);
    setLayout(lay);
}
