#include "infopartitastorico.h"
#include "infopersonaggiostorico.h"

InfoPartitaStorico::InfoPartitaStorico(QWidget *parent) : QWidget(parent){
    QLabel * titolo = new QLabel("Info su partita");
    lay= new QVBoxLayout();
    lay->addWidget(titolo, 0, Qt::AlignCenter);
    setLayout(lay);
}

void InfoPartitaStorico::addPersonaggio(QString n, QString t, QString l, int i){
    InfoPersonaggioStorico * newPers= new InfoPersonaggioStorico(n, t, l, i);
    lay->addWidget(newPers);
}
