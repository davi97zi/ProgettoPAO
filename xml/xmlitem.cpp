#include "xmlitem.h"


int XmlItem::convertToInt() const{
    if(getTipo()=="Arciere")
        return 0;
    if(getTipo()=="Artificiere")
        return 1;
    if(getTipo()=="Berserker")
        return 2;
    if(getTipo()=="Guaritore")
        return 3;
    if(getTipo()=="Mago")
        return 4;
    if(getTipo()=="Paladino")
        return 5;
    if(getTipo()=="Soldato")
        return 6;
    if(getTipo()=="Tank")
        return 7;
}

XmlItem::XmlItem(){}

XmlItem::XmlItem(QString n, QString t, int l, int p): nome(n), tipo(t), livello(l), prezzo(p){}

void XmlItem::stampaItem() const{
    qDebug() << "avventuriero: " << nome;
    qDebug() << "classe: " << tipo;
    qDebug() << "livello: " << livello;
    qDebug() << "paga richiesta: " << prezzo;
}

QString XmlItem::getNome() const{
    return nome;
}

QString XmlItem::getTipo() const{
    return tipo;
}

unsigned int XmlItem::getLivello() const{
    return livello;
}

int XmlItem::getPrezzo() const{
    return prezzo;
}

Personaggio *XmlItem::convertiInPersonaggio() const{
    qDebug()<<"entra in convertiinpersonaggio";
    Personaggio* pers=0;
    switch(convertToInt()){
        case 0: pers= new Arciere(getNome(), (getLivello()-1)*100); break;
        case 1: pers= new Artificiere(getNome(), (getLivello()-1)*100); break;
        case 2: pers= new Berserker(getNome(), (getLivello()-1)*100); break;
        case 3: pers= new Guaritore(getNome(), (getLivello()-1)*100); break;
        case 4: pers= new Mago(getNome(), (getLivello()-1)*100); break;
        case 5: pers= new Paladino(getNome(), (getLivello()-1)*100); break;
        case 6: pers= new Soldato(getNome(), (getLivello()-1)*100); break;
        case 7: pers= new Tank(getNome(), (getLivello()-1)*100); break;
    }
    return pers;
}
