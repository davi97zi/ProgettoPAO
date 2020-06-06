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
    void readTheRoom(const QDomElement & root){
        //entra in primo figlio (adventuriero)
        QDomElement adventurer=root.firstChild().toElement();
        while(!adventurer.isNull()){//leggi tutti gli adventurieri
            readTheAdventurer(adventurer);
            adventurer= adventurer.nextSibling().toElement();
        }
    }

    void readTheAdventurer(const QDomElement & adventurer){
        //dove metto i dati raccolti:
        QString nomeAdv, tipoAdv;
        int livelloAdv, prezzoAdv;
        QDomElement charAdv=adventurer.firstChild().toElement();// entro in primo figlio
        while(!charAdv.isNull()){//leggo le caratteristiche dell'avventuriero
            if(charAdv.tagName()=="nome"){
                nomeAdv= charAdv.firstChild().toText().data();
            }
            if(charAdv.tagName()=="tipo"){
                tipoAdv= charAdv.firstChild().toText().data();
            }
            if(charAdv.tagName()=="livello"){
                livelloAdv= charAdv.firstChild().toText().data().toInt();
            }
            if(charAdv.tagName()=="prezzo"){
                prezzoAdv= charAdv.firstChild().toText().data().toInt();
            }
            //passo alla char successiva:
            charAdv=charAdv.nextSibling().toElement();
        }
        //scrivo caratteristiche in nuovo item
        v.push_back(XmlItem(nomeAdv, tipoAdv, livelloAdv, prezzoAdv));
        //passo all'avventuriero successivo
    }

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
    Taverna(){
        //apri file in lettura
        QFile file("xml/taverna");
        //apro in lettura
        if(file.open(QIODevice::ReadOnly)){
            //carica il file in un QDomDoc
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            qDebug() << "you enter the " << rootElement.tagName();
            readTheRoom(rootElement);

            //close file
            file.close();
        }
        else{//segnalo errore
            qDebug() << "you could not find the tavern, you are lost in the forest, may the gods have mercy on your soul";
        }
    }

    void stampaTutti()const{
        for(auto it= v.begin(); it!=v.end(); it++){
            it->stampaItem();
        }
    }

    //ritorna tutti i personaggi di livello liv (ok?)
    std::vector<XmlItem> trovaTuttiLivello( int liv){
        std::vector<XmlItem> res;
        for(int i= (liv-1)*3; i<liv*3; i++){
            if(v[i].getLivello()==liv){
                res.push_back(v[i]);
            }
        }
        return res;
    }

    XmlItem ingaggia(QString nome, int prezzo){
        XmlItem res;
        bool found=false;
        for(auto it=v.begin(); it!=v.end() && !found; it++){
            if(it->getNome() == nome && it->getPrezzo() == prezzo){
                res=*it;
                v.erase(it);
                found=true;
            }
        }
        if(found){
            qDebug() << "congratulations congratulations congratulations! " << res.getNome() << " is part of your party!";
            return res;
        }
        else{
            qDebug() << "there is no one there with that name or that asks that amount of money";
            //error found! not enough money or the adventurer is not in the tavern (wrong name)
        }


    }

};

#endif // TAVERNA_H
