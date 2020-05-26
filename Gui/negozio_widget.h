#ifndef NEGOZIO_WIDGET_H
#define NEGOZIO_WIDGET_H

#include <QWidget>
#include "negozio_personaggio.h"
#include <QDebug>
#include <QPushButton>
class Negozio_widget : public QWidget{
    Q_OBJECT

private:
    Negozio_personaggio * primo, * secondo, * terzo;
    QLabel * soldi;
    QPushButton * prosegui;
public:
    explicit Negozio_widget(QWidget *parent = nullptr);
    void setPrimo(int i, QString n, QString t, int l, int p);
    void setSecondo(int i, QString n, QString t, int l, int p);
    void setTerzo(int i, QString n, QString t, int l, int p);
    ~Negozio_widget(){qDebug() << "widget eliminato";}
signals:

public slots:
};

#endif // NEGOZIO_WIDGET_H
