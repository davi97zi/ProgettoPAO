#ifndef XMLITEM_H
#define XMLITEM_H
#include <QString>
#include <QDebug>

class XmlItem{
    //dati per la costruzione
    QString nome;
    QString tipo;
    int livello; // da usare come exp!!! (assumo che basti un semplice numero)

    //dati per il display
    int prezzo;

public:
  //base
    XmlItem(){}
  //costruttore devo passare ALL the data
  XmlItem(QString n, QString t, int l, int p): nome(n), tipo(t), livello(l), prezzo(p){}

  //fun stampa
  void stampaItem()const{
      qDebug() << "avventuriero: " << nome;
      qDebug() << "classe: " << tipo;
      qDebug() << "livello: " << livello;
      qDebug() <<"paga richiesta: " << prezzo;
  }

  QString getNome() const{
      return nome;
  }

  QString getTipo() const{
      return tipo;
  }

  int getLivello() const{
      return livello;
  }

  int getPrezzo() const{
      return prezzo;
  }
};
#endif // XMLITEM_H
