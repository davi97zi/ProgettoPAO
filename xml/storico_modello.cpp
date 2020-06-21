#include "storico_modello.h"

StoricoModello::StoricoModello(){
    QFile file("xml/storico");
    //apro in lettura
    if(file.open(QIODevice::ReadOnly)){
        //carica il file in un QDomDoc
        QDomDocument document;
        document.setContent(&file);
        QDomElement rootElement= document.documentElement();
        readTheArchive(rootElement);

        //close file
        file.close();
    }
}


StoricoModello::StoricoModelloItem StoricoModello::getPartita(unsigned int i)const{
    return StoricoModelloPartite[i];
}

unsigned int StoricoModello::getSize()const{
    return StoricoModelloPartite.size();
}

void StoricoModello::addPartita(StoricoModelloItem &item){
    item.setId(StoricoModelloPartite.size()+1);
    StoricoModelloPartite.push_back(item);
}

void StoricoModello::StoricoModelloItem::addItemToSquadra(const XmlItem & item){
    squadra.push_back(item);
}

void StoricoModello::saveStoricoModello()const{
    //apri il file in READ
    QFile file("xml/storico");
    QDomElement rootElement;
    QDomDocument document;
    if(file.open(QIODevice::ReadOnly)){
        //carica l'xml già presente
        document.setContent(&file);
        //tagname storico
        rootElement= document.documentElement();

        //chiudi il file in READ
        file.close();

    //confronta il numero di elementi presenti tra i 2

    unsigned int StoricoModelloSize=StoricoModelloPartite.size();
    unsigned int xmlSize= static_cast<unsigned int>(rootElement.childNodes().size());
    if(xmlSize==0){
        //inserisco il primo elemento nel file
        for(unsigned int i=0; i<StoricoModelloSize; i++){
            StoricoModelloItem s= StoricoModelloPartite[i];
            //crea nuovo elemento
            QDomElement newChild= document.createElement("partita");
            //assegna id
            newChild.setAttribute("id", i);
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
    }
    else{
        unsigned int lastElementId= static_cast<unsigned int>(rootElement.lastChildElement().attribute("id").toInt());
        //aggiungi il prossimo elemento
        for(unsigned int i=lastElementId+1; i<StoricoModelloSize; i++){
            StoricoModelloItem s= StoricoModelloPartite[i];
            //crea nuovo elemento
            QDomElement newChild= document.createElement("partita");
            //assegna id
            newChild.setAttribute("id", i);
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

            //inserisci gli avventurieri
            addSquadra(document, s, newSquadra);

            //assembla i pezzi
            newChild.appendChild(newData);
            newChild.appendChild(newStato);
            newChild.appendChild(newBattaglia);
            newChild.appendChild(newOro);
            newChild.appendChild(newSquadra);

            //aggiungi a root
            rootElement.appendChild(newChild);
        }
    }
    //apri file in write
    QFile fileR("xml/storico");
    if(fileR.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&fileR);
        stream << document;
        fileR.close();
        }
    }
}

XmlItem StoricoModello::readTheAdventurer(const QDomElement & adventurer){
    //dove metto i dati raccolti:
    QString nomeAdv, tipoAdv;
    int livelloAdv=0, prezzoAdv=0;
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
    bool statoPart=true;
    int battagliaPart=0, oroPart=0, idPart=0;
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
                if(charPart.firstChild().toText().data()=="Vittoria")
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
        StoricoModelloItem nuovaPart(static_cast<unsigned int>(idPart), dataPart, statoPart, battagliaPart, oroPart, squadraPart);
        StoricoModelloPartite.push_back(nuovaPart);
        //passo alla partita successiva E azzeri la squadra
        partita= partita.nextSibling().toElement();
        squadraPart.clear();
    }
}

void StoricoModello::aggiungiAvventurieroInXml(QDomDocument &doc, QDomElement& root, XmlItem adv) const{
    //aggiungi nome, tipo, livello, prezzo
    QDomElement newNome= doc.createElement("nome");
    newNome.appendChild(doc.createTextNode(adv.getNome()));

    QDomElement newTipo= doc.createElement("tipo");
    newTipo.appendChild(doc.createTextNode(adv.getTipo()));

    QDomElement newLivello= doc.createElement("livello");
    newLivello.appendChild(doc.createTextNode(QString::number(adv.getLivello())));

    QDomElement newPrezzo= doc.createElement("prezzo");
    newPrezzo.appendChild(doc.createTextNode(QString::number(adv.getPrezzo())));

    root.appendChild(newNome);
    root.appendChild(newTipo);
    root.appendChild(newLivello);
    root.appendChild(newPrezzo);
}

void StoricoModello::addSquadra(QDomDocument &document, StoricoModello::StoricoModelloItem s, QDomElement &newSquadra) const{
    for(int i=0; i<static_cast<int>(s.getSizeSquadra()); i++){
        QDomElement adv=document.createElement("avventuriero");
        aggiungiAvventurieroInXml(document, adv, s.getAvv(i));
        newSquadra.appendChild(adv);
    }
}

StoricoModello::StoricoModelloItem::StoricoModelloItem(QString d, bool v, int b, int o)
    :data(d), vittoria(v), battaglia(b), oro(o){}

StoricoModello::StoricoModelloItem::StoricoModelloItem(unsigned int i, QString d, bool v, int b, int o, std::vector<XmlItem> s)
    :id(i), data(d), vittoria(v), battaglia(b), oro(o), squadra(s){}


unsigned int StoricoModello::StoricoModelloItem::getId() const{ return id;}

QString StoricoModello::StoricoModelloItem::getData() const{ return data;}

QString StoricoModello::StoricoModelloItem::getVittoria() const{ return (vittoria? "Vittoria" : "Sconfitta");}

QString StoricoModello::StoricoModelloItem::getBattaglia() const{ return QString::number(battaglia);}

QString StoricoModello::StoricoModelloItem::getOro() const{ return QString::number(oro);}

unsigned int StoricoModello::StoricoModelloItem::getSizeSquadra() const{ return squadra.size();}

XmlItem StoricoModello::StoricoModelloItem::getAvv(int i) const{return squadra[static_cast<unsigned int>(i)];}

void StoricoModello::StoricoModelloItem::setId(unsigned int s){ id= s;}

void StoricoModello::StoricoModelloItem::setData(){
    QDate today = QDate::currentDate();
    data = today.toString("yyyy/MM/dd");
}

void StoricoModello::StoricoModelloItem::setVittoria(QString s){ vittoria=(s=="Vittoria"? true: false);}

void StoricoModello::StoricoModelloItem::setBattaglia(QString s){ battaglia= s.QString::toInt();}

void StoricoModello::StoricoModelloItem::setOro(QString s){ oro= s.QString::toInt();}


