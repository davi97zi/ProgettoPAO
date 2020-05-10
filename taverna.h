#ifndef TAVERNA_H
#define TAVERNA_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

class Taverna{
private:
    class Item{
    public:
        //dati per la costruzione
        QString nome;
        QString tipo;
        int livello; // da usare come exp!!! (assumo che basti un semplice numero)

        //dati per il display
        int prezzo;

      //costruttore devo passare ALL the data
      Item(QString n, QString t, int l, int p): nome(n), tipo(t), livello(l), prezzo(p){}

      //fun stampa
      void stampaItem()const{
          qDebug() << "avventuriero: " << nome;
          qDebug() << "classe: " << tipo;
          qDebug() << "livello: " << livello;
          qDebug() <<"paga richiesta: " << prezzo;
      }

    };

    std::vector<Item> v;

    //legge un "adventuriero" da "taverna" (file xml)
    void readTheRoom(const QDomElement & root){
        //dove metto i dati raccolti:
        QString nomeAdv, tipoAdv;
        int livelloAdv, prezzoAdv;

        //entra in primo figlio (adventuriero)
        QDomElement adventurer=root.firstChild().toElement();
        while(!adventurer.isNull()){//leggi tutti gli adventurieri
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
            v.push_back(Item(nomeAdv, tipoAdv, livelloAdv, prezzoAdv));
            //passo all'avventuriero successivo
            adventurer= adventurer.nextSibling().toElement();
        }
    }

public:
    //costruttore: usa QXml per recuperare i dati dalla risorsa
    Taverna(){
        //apri file in lettura
        QFile file("taverna");
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
};

#endif // TAVERNA_H
