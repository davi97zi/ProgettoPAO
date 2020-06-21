#ifndef DUNGEON_H
#define DUNGEON_H

#include <QFile>
#include <QtXml>
#include "../personaggi/mostro.h"
#include "xml_item.h"
#include "dungeon_item.h"


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

    //trova il mostro da combattere alla i-esima battaglia
    Mostro* challengeMonster(int);
};

#endif // DUNGEON_H
