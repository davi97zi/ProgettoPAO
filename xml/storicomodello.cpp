#include "storicoModello.h"

StoricoModello::StoricoModello(){
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

void StoricoModello::stampaStoricoModello() const{
    for(auto it=StoricoModelloPartite.begin(); it!= StoricoModelloPartite.end(); it++){
        it->stampaStoricoModelloItem();
    }
}

StoricoModello::StoricoModelloItem StoricoModello::getPartita(unsigned int i)const{return StoricoModelloPartite[i];}

unsigned int StoricoModello::getSize()const{
    return StoricoModelloPartite.size();
}

void StoricoModello::addPartita(QString d, bool v, int b, int o, std::vector<XmlItem> s){
    StoricoModelloPartite.push_back(StoricoModelloItem(StoricoModelloPartite.size()+1, d, v, b, o, s));
}

void StoricoModello::saveStoricoModello()const{
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

XmlItem StoricoModello::readTheAdventurer(const QDomElement &adventurer){//NB! REFACTOR!!! +++ SIMILE A FUN PRESENTE IN TAVERNA.H
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

void StoricoModello::readTheArchive(QDomElement & root){
    //dove metto i dati raccolti:
    QString dataPart;
    bool statoPart;
    int battagliaPart, oroPart, idPart;
    std::vector<XmlItem> squadraPart; //estrai Item da Negozio

    //entra in primo figlio (partita)
    QDomElement partita=root.firstChild().toElement();

    while(!partita.isNull()){//leggi tutte le partite
        idPart=partita.attribute("id").toInt();
        qDebug() << "entro in "<< partita.tagName() << " " << idPart;
        QDomElement charPart=partita.firstChild().toElement();// entro in primo figlio (data)
        while(!charPart.isNull()){//leggo le caratteristiche della partita
            qDebug() << "entro in "<< charPart.tagName() << " " << idPart;

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
                    qDebug() << "sono in : " << advCharPart.tagName();
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
        //passo alla partita successiva E azzeri la squadra
        partita= partita.nextSibling().toElement();
        squadraPart.clear();
    }
}

void StoricoModello::aggiungiAvventurieroInXml(QDomDocument &doc, QDomElement &root, XmlItem adv) const{
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

void StoricoModello::addSquadra(QDomDocument &document, StoricoModello::StoricoModelloItem s, QDomElement &newSquadra) const{
    for(int i= 0; i<s.getSizeSquadra(); i++){
        aggiungiAvventurieroInXml(document, newSquadra, s.getAvv(i));
    }
}

StoricoModello::StoricoModelloItem::StoricoModelloItem(unsigned int i, QString d, bool v, int b, int o, std::vector<XmlItem> s)
    :id(i), data(d), vittoria(v), battaglia(b), oro(o), squadra(s){}

void StoricoModello::StoricoModelloItem::stampaStoricoModelloItem() const{
    qDebug() << "id: " << id;
    qDebug() << "partita giocata il: " << data;
    qDebug() << "risultato: " << (vittoria? "Vittoria": "Sconfitta");
    qDebug() << "profondità del dungeon raggiunto; " << battaglia;
    qDebug() << "oro guadagnato: " << oro;
    qDebug() <<"Squadra: " << squadra.size();
    for(auto it=squadra.begin(); it!=squadra.end(); it++){
        it->stampaItem();
    }
}

unsigned int StoricoModello::StoricoModelloItem::getId() const{ return id;}

QString StoricoModello::StoricoModelloItem::getData() const{ return data;}

QString StoricoModello::StoricoModelloItem::getVittoria() const{ return (vittoria? "Vittoria" : "Sconfitta");}

QString StoricoModello::StoricoModelloItem::getBattaglia() const{ return QString::number(battaglia);}

QString StoricoModello::StoricoModelloItem::getOro() const{ return QString::number(oro);}

int StoricoModello::StoricoModelloItem::getSizeSquadra() const{ return squadra.size();}

XmlItem StoricoModello::StoricoModelloItem::getAvv(int i) const{ qDebug() << "squadra[" << i <<"] :" << squadra[i].getNome();return squadra[i];}

void StoricoModello::StoricoModelloItem::setId(QString s){ id= s.QString::toInt();}

void StoricoModello::StoricoModelloItem::setData(QString s){ data=s.QString::toInt();}

void StoricoModello::StoricoModelloItem::setVittoria(QString s){ vittoria=(s=="Vittoria"? true: false);}

void StoricoModello::StoricoModelloItem::setBattaglia(QString s){ battaglia= s.QString::toInt();}

void StoricoModello::StoricoModelloItem::setOro(QString s){ oro= s.QString::toInt();}


