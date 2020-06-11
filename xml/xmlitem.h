#ifndef XMLITEM_H
#define XMLITEM_H
#include <QString>
#include <QDebug>
#include "../Interfacce/personaggio.h"
#include "../arciere.h"
#include "../artificiere.h"
#include "../berserker.h"
#include "../guaritore.h"
#include "../mago.h"
#include "../paladino.h"
#include "../soldato.h"
#include "../tank.h"

class XmlItem{
    //dati per la costruzione
    QString nome;
    QString tipo;
    int livello; // da usare come exp!!! (assumo che basti un semplice numero)

    //dati per il display
    int prezzo;
    int convertToInt() const;

public:
  //base
    XmlItem();
  //costruttore devo passare ALL the data
  XmlItem(QString n, QString t, int l, int p);

  //fun stampa
  void stampaItem()const;

  QString getNome() const;

  QString getTipo() const;

  unsigned int getLivello() const;

  int getPrezzo() const;



  Personaggio* convertiInPersonaggio() const;
};
#endif // XMLITEM_H
