#include "info_personaggio_storico.h"


InfoPersonaggioStorico::InfoPersonaggioStorico(QString n, QString t, QString l, int i, QWidget *parent) :
    nome(new QLabel(n)), tipo(new QLabel(t)), livello(new QLabel(l)), QWidget(parent){
    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(nome, 0, Qt::AlignCenter);
    lay->addWidget(tipo, 0, Qt::AlignCenter);
    lay->addWidget(livello, 0, Qt::AlignCenter);

    QGroupBox * group= new QGroupBox();
    group->setLayout(lay);
    group->setTitle("personaggio" + QString::number(i));

    QVBoxLayout * container= new QVBoxLayout();
    container->addWidget(group);

    setLayout(container);
    //setLayout(lay);
}
