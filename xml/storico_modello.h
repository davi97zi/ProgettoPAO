#ifndef STORICO_MODELLO_H
#define STORICO_MODELLO_H

#include <vector>
#include <QFile>
#include <QtXml>
#include "xml_item.h"


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
        std::vector<XmlItem> squadra; //estrai Item da Negozio
    public:
        StoricoModelloItem(){}
        StoricoModelloItem(QString d, bool v, int b, int o);
        StoricoModelloItem(unsigned int i,QString d, bool v, int b, int o, std::vector<XmlItem> s);

        void stampaStoricoModelloItem()const;

        unsigned int getId() const;
        QString getData() const;
        QString getVittoria() const;
        QString getBattaglia() const;
        QString getOro() const;
        unsigned int getSizeSquadra() const;
        XmlItem getAvv(int i)const;

        void setId(unsigned int s);
        void setData();
        void setVittoria(QString s);
        void setBattaglia(QString s);
        void setOro(QString s);

        void addItemToSquadra(const XmlItem &);
    };

    StoricoModello();

    void stampaStoricoModello()const;
    StoricoModelloItem getPartita(unsigned int i)const;
    unsigned int getSize()const;

    void addPartita( StoricoModelloItem& );
    void saveStoricoModello()const;

private:

    std::vector<StoricoModelloItem> StoricoModelloPartite;

    XmlItem readTheAdventurer(const QDomElement & adventurer);

    //popola lo StoricoModello alla sua creazione
    void readTheArchive(QDomElement & root);

    void aggiungiAvventurieroInXml(QDomDocument& doc, QDomElement& root, XmlItem adv)const;

    void addSquadra(QDomDocument& document, StoricoModelloItem s, QDomElement & newSquadra)const;

};

#endif // STORICO_MODELLO_H
