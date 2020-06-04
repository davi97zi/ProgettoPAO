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
    XmlItem();
  //costruttore devo passare ALL the data
  XmlItem(QString n, QString t, int l, int p);

  //fun stampa
  void stampaItem()const;

  QString getNome() const;

  QString getTipo() const;

  int getLivello() const;

  int getPrezzo() const;
};
#endif // XMLITEM_H
