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

public slots:
    void slotQualeBottone(QString);
    void remakeMain();
    void stampaRowInfo(int);
    void creaPersonaggio(int);
};

#endif // CONTROLLER_H
