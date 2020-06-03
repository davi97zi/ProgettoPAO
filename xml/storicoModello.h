#ifndef STORICOMODELLO_H
#define STORICOMODELLO_H

#include <vector> //TEMP!
#include <QDebug>
#include <QFile>
#include <QtXml>

#include "xmlitem.h"

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
        StoricoModelloItem(unsigned int i,QString d, bool v, int b, int o, std::vector<XmlItem> s):id(i), data(d), vittoria(v), battaglia(b), oro(o), squadra(s){}
        /*
        //fun stampa partita
        void stampaStoricoModelloItem()const{
            qDebug() << "id: " << id;
            qDebug() << "partita giocata il: " << data;
            qDebug() << "risultato: " << (vittoria? "Vittoria": "Sconfitta");
            qDebug() << "profondità del dungeon raggiunto; " << battaglia;
            qDebug() << "oro guadagnato: " << oro;
            qDebug() <<"Squadra: ";
            for(auto it=squadra.begin(); it!=squadra.end(); it++){
                it->stampaItem();
            }
        }*/

        //getters:
        unsigned int getId() const{ return id;}
        QString getData() const{ return data;}
        QString getVittoria() const{ return (vittoria? "Vittoria" : "Sconfitta");}
        QString getBattaglia() const{ return QString::number(battaglia);}
        QString getOro() const{ return QString::number(oro);}
        QString getSizeSquadra() const{ return QString::number(squadra.size());}
        XmlItem getAvv(int i)const{ return squadra[i];}

        void setId(QString s){ id= s.QString::toInt();}
        void setData(QString s){ data=s.QString::toInt();}
        void setVittoria(QString s){ vittoria=(s=="Vittoria"? true: false);}
        void setBattaglia(QString s){ battaglia= s.QString::toInt();}
        void setOro(QString s){ oro= s.QString::toInt();;}
        //void setSizeSquadra(QString s){ ;}
        //void setAvv(XmlItem){ ;} // 1 sec
    };

    StoricoModello(){
        QFile file("xml/storico");
        //apro in lettura
        if(file.open(QIODevice::ReadOnly)){
            //carica il file in un QDomDoc
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            qDebug() << "you enter the " << rootElement.tagName();
            readTheArchive(rootElement);

            qDebug()<< "creato lo StoricoModello";

            //close file
            file.close();
        }
        else{//segnalo errore
            qDebug() << "you could not find the tavern, you are lost in the forest, may the gods have mercy on your soul";
        }
    }

    /*
    void stampaStoricoModello()const{
        for(auto it=StoricoModelloPartite.begin(); it!= StoricoModelloPartite.end(); it++){
            it->stampaStoricoModelloItem();
        }
    }*/

    StoricoModelloItem getPartita(unsigned int i)const{
        return StoricoModelloPartite[i];
    }

    unsigned int getSize()const{
        return StoricoModelloPartite.size();
    }
/*
    //add partita in vettore interno e chiama x inserirlo in xml file
    void addPartita(QString d, bool v, unsigned int b, unsigned int o, ????){

    }
*/

    //1 salva in vectorQString data; NB not gonna be a std::vector in the true one
    //QString d, bool v, int b, int o, std::vector<XmlItem> s
    void addPartita(QString d, bool v, int b, int o, std::vector<XmlItem> s){
        StoricoModelloPartite.push_back(StoricoModelloItem(StoricoModelloPartite.size()+1, d, v, b, o, s));
    }

    void saveStoricoModello()const{
        //apri il file in READ
        QFile file("xml/storico");
        if(file.open(QIODevice::ReadOnly)){
            //carica l'xml già presente
            QDomDocument document;
            document.setContent(&file);
            QDomElement rootElement= document.documentElement();
            //chiudi il file in READ
            file.close();
            //confronta il numero di elementi presenti tra i 2

            unsigned int lastElementId= rootElement.lastChildElement().attribute("id").toInt(), StoricoModelloSize=StoricoModelloPartite.size();
            qDebug() << lastElementId << " " <<StoricoModelloSize;

            if(lastElementId!=StoricoModelloSize){//esiste elementi da inserire in xml
                for(unsigned int i=lastElementId; i<StoricoModelloSize; i++){
                    StoricoModelloItem s= StoricoModelloPartite[i];
                    //crea nuovo elemento
                    QDomElement newChild= document.createElement("partita");
                    //assegna id
                    newChild.setAttribute("id", i+1);
                    //crea gli elementi caratteristiche e popolali
                    QDomElement newData= document.createElement("data");
                    newData.appendChild( document.createTextNode(s.getData()));

                    QDomElement newStato= document.createElement("stato");
                    newStato.appendChild( document.createTextNode(s.getVittoria()));

                    QDomElement newBattaglia= document.createElement("battaglia");
                    newBattaglia.appendChild( document.createTextNode(s.getBattaglia()));

                    QDomElement newOro= document.createElement("oro");
                    newOro.appendChild(document.createTextNode(s.getOro()));

                    QDomElement newSquadra= document.createElement("squadra");

                    //inserisci gli avventurieri, something
                    addSquadra(document, s, newSquadra); //RITORNA

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
                QFile fileR("xml/storico");
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

private:

    //static const QString StoricoModelloFile;
    std::vector<StoricoModelloItem> StoricoModelloPartite; //posso usare vector???

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

    //popola lo StoricoModello alla sua creazione
    void readTheArchive(QDomElement root){
        //dove metto i dati raccolti:
        QString dataPart;
        bool statoPart;
        int battagliaPart, oroPart, idPart;
        std::vector<XmlItem> squadraPart; //estrai Item da Negozio

        //entra in primo figlio (partita)
        QDomElement partita=root.firstChild().toElement();

        while(!partita.isNull()){//leggi tutte le partite
            idPart=partita.attribute("id").toInt();
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
            StoricoModelloItem nuovaPart(idPart, dataPart, statoPart, battagliaPart, oroPart, squadraPart);
            StoricoModelloPartite.push_back(nuovaPart);
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

    void addSquadra(QDomDocument& document, StoricoModelloItem s, QDomElement & newSquadra)const{
        for(int i= 0; i<s.getSizeSquadra(); i++){
            aggiungiAvventurieroInXml(document, newSquadra, s.getAvv(i));
        }
    }

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

#endif // StoricoModelloMODELLO_H
