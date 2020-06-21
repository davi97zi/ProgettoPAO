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


class XmlItem{
    QString nome;
    QString tipo;
    int livello; // da usare come exp!!!

    int prezzo;
    int convertToInt() const;

public:

    XmlItem();

    XmlItem(QString n, QString t, int l, int p);
    void stampaItem()const;

    QString getNome() const;
    QString getTipo() const;
    unsigned int getLivello() const;
    int getPrezzo() const;

    Personaggio* convertiInPersonaggio() const;
};
#endif // XML_ITEM_H
