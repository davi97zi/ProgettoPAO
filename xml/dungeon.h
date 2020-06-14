#ifndef DUNGEON_H
#define DUNGEON_H

#include "xmlitem.h"
#include "dungeonItem.h"
#include "../mostro.h"


#include <QDebug>
#include <QFile>
#include <QtXml>


class Dungeon{

private:

    std::vector<DungeonItem> v;

    //legge tutti i "mostro" da "dungeon" (file xml)
    void fillTheDungeon(const QDomElement&);

    //costruisce un mostro
    void faceTheMonster(const QDomElement&);

public:

    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Dungeon();

    /*void stampaTutti()const{
        for(auto it= v.begin(); it!=v.end(); it++){
            it->stampaDungeonItem();
        }
    }*/

    //trova il mostro da combattere alla i-esima battaglia
    Mostro* challengeMonster(int);
};

#endif // DUNGEON_H
