#ifndef INCANTESIMO_H
#define INCANTESIMO_H

#include <QString>
#include <QFile>
#include <QtXml>

class Incantesimo{
private:
    QString nome, descrizione; // nome potrebbe essere usato x ritornare il valore da visualizzare sul bottone a video
    QDomElement findOnXml(const QDomElement& root, QString tipo, int num);
public:
    //INCANTESIMO STD X SICUREZZA
    //Incantesimo(){}

    //costruttore crea l'incantesimo, in base al tipo E al num richiesto, cercandolo nel file xml incantesimi
    Incantesimo(QString tipo, int num);

    //getter x il nome
    QString getNome() const;
    //getter x la descrizione
    QString getString() const;
};
#endif // INCANTESIMO_H
