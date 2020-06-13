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

    void eseguiAbilita(int, bool);
public:
    explicit Controller(QObject *parent = nullptr);

    void creaMatch();
    void getMostro(int); //should be const?

public slots:
    void slotQualeBottone(QString);
    void remakeMain();
    void stampaRowInfo(unsigned int);
    void creaPersonaggio(unsigned int);
    void getAction(QString);

signals:
    void updatedHPMostro(int);
    void updatedArmPersonaggio(int);
    void updatedHealthPersonaggio(int);
};

#endif // CONTROLLER_H
