#ifndef XML_ITEM_H
#define XML_ITEM_H

#include "../interfacce/personaggio.h"
#include "../personaggi/arciere.h"
#include "../personaggi/artificiere.h"
#include "../personaggi/berserker.h"
#include "../personaggi/guaritore.h"
#include "../personaggi/mago.h"
#include "../personaggi/paladino.h"
#include "../personaggi/soldato.h"
#include "../personaggi/tank.h"
#include <QString>

#include <QDebug>

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
#endif // XML_ITEM_H
