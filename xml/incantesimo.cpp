#include "incantesimo.h"

Incantesimo::Incantesimo(QString tipo, int num){
    //apri file in lettura
    QFile file("incantesimi");
    //apro in lettura
    if(file.open(QIODevice::ReadOnly)){
        //carica il file in un QDomDoc
        QDomDocument document;
        document.setContent(&file);
        //trova il primo figlio (contiene all else)
        QDomElement rootElement= document.documentElement();
        qDebug() << "found the " << rootElement.tagName();

        //trova il nodo rilevante usando il tipo e il num dell'abilita
        QDomElement incantesimoMaker= findOnXml(rootElement, tipo, num);
        //inserisci le 2 caratteristiche nei campi dedicati
        nome= incantesimoMaker.firstChildElement("nome").text();
        descrizione= incantesimoMaker.firstChildElement("descrizione").text();
        //close file
        file.close();
    }
    else{//segnalo errore
        qDebug() << "you got amnesia and forgot all your abilities";
    }
}


QDomElement Incantesimo::findOnXml(const QDomElement& root, QString tipo, int num){
    //scorri i tipi fino a trovare il tuo
    QDomElement elementTipo= root.firstChild().toElement();
    bool foundType= false;
    while(!elementTipo.isNull() && !foundType){
        QString attrTipo= elementTipo.attribute("nome");
        if(attrTipo==tipo){//siamo sull'elemento cercato, stop
            foundType=true;
        }
        else{//non è il tipo giusto, prosegui
            elementTipo=elementTipo.nextSibling().toElement();
        }
    }
    if(foundType){//ho trovato il tipo, cerco il num
        QDomElement elementAbilita= elementTipo.firstChild().toElement();
        bool foundNum=false;
        while(!elementAbilita.isNull() && !foundNum){
            int attrAbilita= elementAbilita.attribute("num").QString::toInt();
            if(attrAbilita==num){
                foundNum=true;
            }
            else{
                elementAbilita= elementAbilita.nextSibling().toElement();
            }
        }
        if(foundNum){// ho trovato il num, ritorno l'elemento
            return elementAbilita;
        }
        else{//error
            qDebug() << "errore, il num " << num << " non esiste";
        }
    }
    else{//errore, il tipo non esiste
        qDebug() << "errore, il tipo " << tipo << " non esiste";
    }
}

//getter x il nome
QString Incantesimo::getNome() const{
    return nome;
}
//getter x la descrizione
QString Incantesimo::getString() const{
    return descrizione;
}
