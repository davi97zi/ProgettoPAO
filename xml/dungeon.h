#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

#include "xmlitem.h"
#include "dungeonItem.h"
#include "../mostro.h"


class Dungeon{

private:

    std::vector<DungeonItem> v;

    //legge tutti i "mostro" da "dungeon" (file xml)
    void fillTheDungeon(const QDomElement & root);

    //costruisce un mostro
    void faceTheMonster(const QDomElement & monster);

public:

    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Dungeon();

    /*void stampaTutti()const{
        for(auto it= v.begin(); it!=v.end(); it++){
            it->stampaDungeonItem();
        }
    }*/

    //trova il mostro da combattere alla i-esima battaglia
    Mostro* challengeMonster(int i);
};

#endif // DUNGEON_H
