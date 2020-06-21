#ifndef TAVERNA_H
#define TAVERNA_H

#include <vector>
#include <QFile>
#include <QtXml>
#include "xml_item.h"
#include "../interfacce/personaggio.h"


class Taverna{
private:
    std::vector<XmlItem> v;

    //legge un "avventuriero" da "taverna" (file xml)
    void readTheRoom(const QDomElement & root);

    void readTheAdventurer(const QDomElement & adventurer);

public:

    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Taverna();
    void stampaTutti()const;

    //ritorna tutti i personaggi di livello liv
    std::vector<XmlItem> trovaTuttiLivello(int liv);

    XmlItem ingaggia(QString nome, int prezzo);

};

#endif // TAVERNA_H
