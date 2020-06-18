#ifndef DUNGEON_ITEM_H
#define DUNGEON_ITEM_H

#include <QString>

class DungeonItem{
private:
    QString nome, descrizione;
    int livello, exp, oro;
public:
    DungeonItem(QString n, int l, int e, int o, QString d): nome(n), descrizione(d), livello(l), exp(e), oro(o){}
    /*void stampaDungeonItem()const{
        qDebug() << nome;
        qDebug() << "is a level: " << livello << " monster";
        qDebug() << descrizione;
        qDebug() << "the rewards for killing it are: ";
        qDebug() << exp << " experience points and " << oro << " gold!";
    }*/

    QString getNome() const;
    QString getDescrizione() const;
    int getLivello() const;
    int getExp() const;
    int getOro() const;
};


#endif // DUNGEON_ITEM_H
