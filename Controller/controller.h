#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include "../gui/main_window.h"
#include "../gui/negozio_widget.h"
#include "../gui/storico.h"
#include "../gui/info_partita_storico.h"
#include "../gui/match.h"
#include "../gui/change_character.h"
#include "../gui/statistiche_match_personaggio.h"
#include "../gui/statistiche_match_mostro.h"
#include "../xml/storico_modello.h"
#include "../xml/taverna.h"
#include "../xml/dungeon.h"
#include "../partita.h"


class Controller : public QObject{
    Q_OBJECT

private:
    MainWindow * mw;
    Partita * pMod;
    StoricoModello * sMod;
    StatisticheMatchPersonaggio* smp;

    void eseguiAbilita(int, bool);

public:
    explicit Controller(QObject *parent = nullptr);

    void creaMatch();
    void getMostro(int);
    void monsterAttack();
    void endRoundActions();
    void creaNuovoNegozio();
    //void aggiornaDatiPersonaggio();
    void setVistaCambiaPersonaggio();

public slots:
    void slotQualeBottone(QString);
    void remakeMain();
    void stampaRowInfo(int);
    void creaPersonaggio(int);
    void getAction(QString);
    void createNewMatch();
    void cambiaPersonaggioController(QString);

signals:
    void updatedHPMostro(int);
    void updatedArmPersonaggio(int);
    void updatedHealthPersonaggio(int);
    void updatedManaPersonaggio(int);
    void newMatch();
};

#endif // CONTROLLER_H
