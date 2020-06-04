#include "xmlitem.h"


XmlItem::XmlItem(){}

XmlItem::XmlItem(QString n, QString t, int l, int p): nome(n), tipo(t), livello(l), prezzo(p){}

void XmlItem::stampaItem() const{
    qDebug() << "avventuriero: " << nome;
    qDebug() << "classe: " << tipo;
    qDebug() << "livello: " << livello;
    qDebug() <<"paga richiesta: " << prezzo;
}

QString XmlItem::getNome() const{
    return nome;
}

QString XmlItem::getTipo() const{
    return tipo;
}

int XmlItem::getLivello() const{
    return livello;
}

int XmlItem::getPrezzo() const{
    return prezzo;
}
