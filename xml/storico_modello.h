#ifndef STORICO_MODELLO_H
#define STORICO_MODELLO_H

#include <vector> //TEMP!
#include <QFile>
#include <QtXml>
#include "xml_item.h"

#include <QDebug>

class StoricoModello{

public:
    //crea lo StoricoModello
    class StoricoModelloItem{
    private:
        unsigned int id;
        QString data;
        bool vittoria;
        int battaglia;
        int oro;
        std::vector<XmlItem> squadra; //estrai Item da Negozio CAN I USE VECTOR????
    public:
        StoricoModelloItem(){}
        StoricoModelloItem(QString d, bool v, int b, int o);
        StoricoModelloItem(unsigned int i,QString d, bool v, int b, int o, std::vector<XmlItem> s);

        //fun stampa partita
        void stampaStoricoModelloItem()const;

        //getters:
        unsigned int getId() const;
        QString getData() const;
        QString getVittoria() const;
        QString getBattaglia() const;
        QString getOro() const;
        int getSizeSquadra() const;
        XmlItem getAvv(int i)const;

        void setId(unsigned int s);
        void setData();
        void setVittoria(QString s);
        void setBattaglia(QString s);
        void setOro(QString s);
        //void setSizeSquadra(QString s){ ;}
        //void setAvv(XmlItem){ ;} // 1 sec

        void addItemToSquadra(const XmlItem &);
    };

    StoricoModello();

    void stampaStoricoModello()const;

    StoricoModelloItem getPartita(unsigned int i)const;

    unsigned int getSize()const;
/*
    //add partita in vettore interno e chiama x inserirlo in xml file
    void addPartita(QString d, bool v, unsigned int b, unsigned int o, ????){

    }
*/

    //1 salva in vectorQString data; NB not gonna be a std::vector in the true one
    //QString d, bool v, int b, int o, std::vector<XmlItem> s
    void addPartita( StoricoModelloItem& );

    void saveStoricoModello()const;

private:

    //static const QString StoricoModelloFile;
    std::vector<StoricoModelloItem> StoricoModelloPartite; //posso usare vector???

    XmlItem readTheAdventurer(const QDomElement & adventurer);

    //popola lo StoricoModello alla sua creazione
    void readTheArchive(QDomElement & root);

    void aggiungiAvventurieroInXml(QDomDocument& doc, QDomElement& root, XmlItem adv)const;

    void addSquadra(QDomDocument& document, StoricoModelloItem s, QDomElement & newSquadra)const;

/*
    void aggiungiPartitaInXml(QDomDocument& doc, QDomElement& root, int i)const{// make a node from info at StoricoModelloPartite[i]

        StoricoModelloItem s= StoricoModelloPartite[i];
        //crea nuovo elemento
        QDomElement newChild= doc.createElement("partita");
        //assegna id
        newChild.setAttribute("id", i+1);
        //crea gli elementi caratteristiche e popolali
        QDomElement newData= doc.createElement("data");
        newData.appendChild( doc.createTextNode(s.data));

        QDomElement newStato= doc.createElement("stato");
        newStato.appendChild( doc.createTextNode(s.vittoria? "vittoria" : "sconfitta"));

        QDomElement newBattaglia= doc.createElement("battaglia");
        newBattaglia.appendChild( doc.createTextNode(QString::number(s.battaglia)));

        QDomElement newOro= doc.createElement("oro");
        newOro.appendChild((doc.createTextNode(QString::number(s.oro))));

        QDomElement newSquadra= doc.createElement("squadra");

        //inserisci gli avventurieri, something
        for(auto it= s.squadra.begin(); it!=s.squadra.end(); it++){
            aggiungiAvventurieroInXml(doc, newSquadra, *it);
        }

        //assembla i pezzi
        newChild.appendChild(newData);
        newChild.appendChild(newStato);
        newChild.appendChild(newBattaglia);
        newChild.appendChild(newOro);
        newChild.appendChild(newSquadra);

        //aggiungi a root
        root.appendChild(newChild);
    }
*/

};

//const QString StoricoModello::StoricoModelloFile="StoricoModello";

#endif // STORICO_MODELLO_H
