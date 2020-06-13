#ifndef TAVERNA_H
#define TAVERNA_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

#include "xmlitem.h"

#include "Interfacce/personaggio.h"

class Taverna{
private:
    std::vector<XmlItem> v;

    //legge un "adventuriero" da "taverna" (file xml)
    void readTheRoom(const QDomElement & root);

    void readTheAdventurer(const QDomElement & adventurer);

    /*void ingaggiaAdv(QString nome, int gold){
        std::vector<XmlItem>::iterator it=v.begin();
        while(it!=v.end() && it->nome!= nome){
            qDebug() << it->nome;
            it++;
        }
        if(it!=v.end() && gold==it->prezzo){
            v.erase(it);
        }
    }*/

public:

    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Taverna();

    void stampaTutti()const;

    //ritorna tutti i personaggi di livello liv (ok?)
    std::vector<XmlItem> trovaTuttiLivello(unsigned int liv);

    XmlItem ingaggia(QString nome, int prezzo);

};

#endif // TAVERNA_H
