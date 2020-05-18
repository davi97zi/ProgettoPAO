#ifndef STORICO_H
#define STORICO_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

#include "xmlitem.h"

class Storico{
private:

    static const QString storicoFile;

    class StoricoItem{
    public:
        unsigned int id;
        QString data;
        bool vittoria;
        int battaglia;
        int oro;
        std::vector<XmlItem> squadra; //estrai Item da Negozio
        StoricoItem(unsigned int i,QString d, bool v, int b, int o, std::vector<XmlItem> s):id(i), data(d), vittoria(v), battaglia(b), oro(o), squadra(s){}

        //fun stampa partita
        void stampaStoricoItem()const{
            qDebug() << "id: " << id;
            qDebug() << "partita giocata il: " << data;
            qDebug() << "risultato: " << (vittoria? "Vittoria": "Sconfitta");
            qDebug() << "profondità del dungeon raggiunto; " << battaglia;
            qDebug() << "oro guadagnato: " << oro;
            qDebug() <<"Squadra: ";
            for(auto it=squadra.begin(); it!=squadra.end(); it++){
                it->stampaItem();
            }
        }
    };

    std::vector<StoricoItem> storicoPartite;

    XmlItem readTheAdventurer(const QDomElement & adventurer){//NB! REFACTOR!!! +++ SIMILE A FUN PRESENTE IN TAVERNA.H
        //dove metto i dati raccolti:
        QString nomeAdv, tipoAdv;
        int livelloAdv, prezzoAdv;
        //
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
        return XmlItem(nomeAdv, tipoAdv, livelloAdv, prezzoAdv);
    }

    //popola lo storico alla sua creazione
    void readTheArchive(QDomElement root){
        //dove metto i dati raccolti:
        QString dataPart;
        bool statoPart;
        int battagliaPart, oroPart, idPart;
        std::vector<XmlItem> squadraPart; //estrai Item da Negozio

        //entra in primo figlio (partita)
        QDomElement partita=root.firstChild().toElement();
        idPart=partita.attribute("id").toInt();

        while(!partita.isNull()){//leggi tutte le partite
            QDomElement charPart=partita.firstChild().toElement();// entro in primo figlio (data)
            while(!charPart.isNull()){//leggo le caratteristiche della partita
                if(charPart.tagName()=="data"){
                    dataPart= charPart.firstChild().toText().data();
                }
                if(charPart.tagName()=="stato"){
                    if(charPart.firstChild().toText().data()=="vittoria")
                        statoPart= true;
                    else
                        statoPart=false;
                }
                if(charPart.tagName()=="battaglia"){
                    battagliaPart= charPart.firstChild().toText().data().toInt();
                }
                if(charPart.tagName()=="oro"){
                    oroPart= charPart.firstChild().toText().data().toInt();
                }
                if(charPart.tagName()=="squadra"){
                    //gotta get ALL inside of squadraPart
                    //leggi il primo elemento adv
                    QDomElement advCharPart(charPart.firstChildElement());
                    //scorri gli avventurieri
                    while(!advCharPart.isNull()){
                        squadraPart.push_back(readTheAdventurer(advCharPart));
                        advCharPart= advCharPart.nextSibling().toElement();
                    }

                }
                //passo alla char successiva:
                charPart=charPart.nextSibling().toElement();
            }
            //scrivo caratteristiche in nuovo item
            StoricoItem nuovaPart(idPart, dataPart, statoPart, battagliaPart, oroPart, squadraPart);
            storicoPartite.push_back(nuovaPart);
            //passo all'avventuriero successivo
            partita= partita.nextSibling().toElement();
        }
    }

    void aggiungiAvventurieroInXml(QDomDocument& doc, QDomElement& root, XmlItem adv)const{
        //aggiungi nome, tipo, livello, prezzo
        QDomElement newNome= doc.createElement("nome");
        newNome.appendChild( doc.createTextNode(adv.getNome()));

        QDomElement newTipo= doc.createElement("tipo");
        newTipo.appendChild( doc.createTextNode(adv.getTipo()));

        QDomElement newLivello= doc.createElement("livello");
        newLivello.appendChild( doc.createTextNode(QString::number(adv.getLivello())));

        QDomElement newPrezzo= doc.createElement("prezzo");
        newPrezzo.appendChild( doc.createTextNode(QString::number(adv.getPrezzo())));

        //put'em where they need to be
        root.appendChild(newNome);
        root.appendChild(newTipo);
        root.appendChild(newLivello);
        root.appendChild(newPrezzo);

    }

/*
    void aggiungiPartitaInXml(QDomDocument& doc, QDomElement& root, int i)const{// make a node from info at storicoPartite[i]

        StoricoItem s= storicoPartite[i];
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
public:
    //crea lo storico
    Storico(){
        QFile file(storicoFile);
        //apro in lettura
        if(file.open(QIODevice::ReadOnly)){
            //carica il file in un QDomDoc
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            qDebug() << "you enter the " << rootElement.tagName();
            readTheArchive(rootElement);

            qDebug()<< "creato lo storico";

            //close file
            file.close();
        }
        else{//segnalo errore
            qDebug() << "you could not find the tavern, you are lost in the forest, may the gods have mercy on your soul";
        }
    }

    void stampaStorico()const{
        for(auto it=storicoPartite.begin(); it!= storicoPartite.end(); it++){
            it->stampaStoricoItem();
        }
    }
/*
    //add partita in vettore interno e chiama x inserirlo in xml file
    void addPartita(QString d, bool v, unsigned int b, unsigned int o, ????){

    }
*/

    //1 salva in vectorQString data; NB not gonna be a std::vector in the true one
    //QString d, bool v, int b, int o, std::vector<XmlItem> s
    void addPartita(QString d, bool v, int b, int o, std::vector<XmlItem> s){
        storicoPartite.push_back(StoricoItem(storicoPartite.size()+1, d, v, b, o, s));
    }

    void saveStorico()const{
        //apri il file in READ
        QFile file(storicoFile);
        if(file.open(QIODevice::ReadOnly)){
            //carica l'xml già presente
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            //chiudi il file in READ
            file.close();
            //confronta il numero di elementi presenti tra i 2

            int lastElementId= rootElement.lastChildElement().attribute("id").toInt(), storicoSize=storicoPartite.size();
            qDebug() << lastElementId << " " <<storicoSize;

            if(lastElementId!=storicoSize){//esiste elementi da inserire in xml
                for(int i=lastElementId; i<storicoSize; i++){
                    StoricoItem s= storicoPartite[i];
                    //crea nuovo elemento
                    QDomElement newChild= document.createElement("partita");
                    //assegna id
                    newChild.setAttribute("id", i+1);
                    //crea gli elementi caratteristiche e popolali
                    QDomElement newData= document.createElement("data");
                    newData.appendChild( document.createTextNode(s.data));

                    QDomElement newStato= document.createElement("stato");
                    newStato.appendChild( document.createTextNode(s.vittoria? "vittoria" : "sconfitta"));

                    QDomElement newBattaglia= document.createElement("battaglia");
                    newBattaglia.appendChild( document.createTextNode(QString::number(s.battaglia)));

                    QDomElement newOro= document.createElement("oro");
                    newOro.appendChild((document.createTextNode(QString::number(s.oro))));

                    QDomElement newSquadra= document.createElement("squadra");

                    //inserisci gli avventurieri, something
                    for(auto it= s.squadra.begin(); it!=s.squadra.end(); it++){
                        aggiungiAvventurieroInXml(document, newSquadra, *it);
                    }

                    //assembla i pezzi
                    newChild.appendChild(newData);
                    newChild.appendChild(newStato);
                    newChild.appendChild(newBattaglia);
                    newChild.appendChild(newOro);
                    newChild.appendChild(newSquadra);

                    //aggiungi a root
                    rootElement.appendChild(newChild);
                }
                //apri file in write
                QFile fileR(storicoFile);
                if(fileR.open(QIODevice::WriteOnly | QIODevice::Text)){
                    QTextStream stream(&fileR);
                    //sovrascrivi...tutto i guesssssssss
                    stream << document.toString();
                    fileR.close();
                    qDebug() << "Writing is done";
                }
                else{
                    qDebug() << "error could not open file to write";
                }
            }//else= do notting, all is fine
        }
        else{
            qDebug() << "error could not open to read file";
        }
    }

};

const QString Storico::storicoFile="storico";

#endif // STORICO_H
