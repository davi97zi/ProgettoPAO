#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

#include "xmlitem.h"
#include "dungeonItem.h"


class Dungeon{

private:

    std::vector<DungeonItem> v;

    //legge tutti i "mostro" da "dungeon" (file xml)
    void fillTheDungeon(const QDomElement & root){
        //entra in primo figlio (Monenturiero)
        QDomElement monster=root.firstChild().toElement();
        while(!monster.isNull()){//leggi tutti gli Monenturieri
            faceTheMonster(monster);
            monster= monster.nextSibling().toElement();
        }
    }

    //costruisce un mostro
    void faceTheMonster(const QDomElement & monster){
        //dove metto i dati raccolti:
        QString nomeMon, descrizioneMon;
        int livelloMon, expMon, oroMon;
        QDomElement charMon=monster.firstChild().toElement();// entro in primo figlio
        while(!charMon.isNull()){//leggo le caratteristiche del mostro
            if(charMon.tagName()=="nome"){
                nomeMon= charMon.firstChild().toText().data();
            }
            if(charMon.tagName()=="livello"){
                livelloMon= charMon.firstChild().toText().data().toInt(); //NB returns GIBBERISH! ALL INTS HERE DO!!!
            }
            if(charMon.tagName()=="exp"){
                expMon= charMon.firstChild().toText().data().toInt();
            }
            if(charMon.tagName()=="oro"){
                oroMon= charMon.firstChild().toText().data().toInt();
            }
            if(charMon.tagName()=="descrizione"){
                descrizioneMon= charMon.firstChild().toText().data();
            }
            //passo alla char successiva:
            charMon=charMon.nextSibling().toElement();
        }
        //scrivo caratteristiche in nuovo item
        v.push_back(DungeonItem(nomeMon, livelloMon, expMon, oroMon, descrizioneMon));
        //passo all'avventuriero successivo
    }

public:

    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Dungeon(){
        //apri file in lettura
        QFile file("dungeon");
        //apro in lettura
        if(file.open(QIODevice::ReadOnly)){
            //carica il file in un QDomDoc
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            qDebug() << "you enter the " << rootElement.tagName();
            fillTheDungeon(rootElement);

            //close file
            file.close();
        }
        else{//segnalo errore
            qDebug() << "you got lost the dungeon is on the other side of the forest!";
        }
    }

    void stampaTutti()const{
        for(auto it= v.begin(); it!=v.end(); it++){
            it->stampaDungeonItem();
        }
    }

    //trova il mostro da combattere alla i-esima battaglia
    DungeonItem challengeMonster(int i){
        return v[i];
    }
};

#endif // DUNGEON_H
