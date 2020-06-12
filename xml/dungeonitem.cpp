#include "../xml/dungeonItem.h"

QString DungeonItem::getNome() const{
    return nome;
}

QString DungeonItem::getDescrizione() const{
    return descrizione;
}

int DungeonItem::getExp() const{
    return exp;
}

int DungeonItem::getLivello() const{
    return livello;
}

int DungeonItem::getOro() const{
    return oro;
}
