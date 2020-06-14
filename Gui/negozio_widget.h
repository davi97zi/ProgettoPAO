#ifndef NEGOZIO_WIDGET_H
#define NEGOZIO_WIDGET_H

#include <QWidget>
#include "negozio_personaggio.h"
#include <QDebug>
#include <QPushButton>
#include "xml/xmlitem.h"

class Negozio_widget : public QWidget{
    Q_OBJECT

private:
    Negozio_personaggio * primo, * secondo, * terzo;
    QLabel * soldi;
    QPushButton * prosegui;
    int monete;
public:
    explicit Negozio_widget(std::vector<XmlItem> assoldabili , int m, bool inizio= false, QWidget *parent = nullptr);
    void setPersonaggioNegozio(int quale, QString n, QString t, int l, int p);
    ~Negozio_widget(){qDebug() << "widget eliminato";}
signals:
    void personaggioAcquistato(int);
    void newMatch();

public slots:
    void stampaDaNegozio(int);
    void proseguiMatch();

};

#endif // NEGOZIO_WIDGET_H
