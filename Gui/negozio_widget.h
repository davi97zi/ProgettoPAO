#ifndef NEGOZIO_WIDGET_H
#define NEGOZIO_WIDGET_H

#include <QWidget>
#include "negozio_personaggio.h"

class Negozio_widget : public QWidget
{
    Q_OBJECT

private:
    Negozio_personaggio * primo, * secondo, * terzo;
public:
    explicit Negozio_widget(QWidget *parent = nullptr);
    void setPrimo(int i, QString n, QString t, int l, int p);
    void setSecondo(int i, QString n, QString t, int l, int p);
    void setTerzo(int i, QString n, QString t, int l, int p);
signals:

public slots:
};

#endif // NEGOZIO_WIDGET_H
