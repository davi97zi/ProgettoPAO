#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Gui/mainwindow.h"
#include "../partita.h"
#include "../xml/storicoModello.h"

class Controller : public QObject{
    Q_OBJECT

private:
    MainWindow * mw;
    Partita * pMod;
    StoricoModello * sMod;

public:
    explicit Controller(QObject *parent = nullptr);

signals:
    //signalBottone(QString);

public slots:
    void slotQualeBottone(QString);
};

#endif // CONTROLLER_H
