#ifndef MATCH_H
#define MATCH_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "abilita_personaggio_match.h"
#include "info_match.h"
#include "statistiche_match_mostro.h"
#include "statistiche_match_personaggio.h"

class Match: public QWidget{
    Q_OBJECT

private:
    QWidget* window;
    QVBoxLayout* contenitore;
    QGridLayout* layoutMostro;
    QGridLayout* layoutPersonaggio;
    QLabel* turno;
    QLabel* coins;

    StatisticheMatchPersonaggio* statsP;
    StatisticheMatchMostro* statsM;

public:
    Match(StatisticheMatchMostro* smm, StatisticheMatchPersonaggio* smp, int t, int m, QWidget* parent=0);

public slots:
    void sendAction(QString);

signals:
    void eseguiAbilitaP(QString);
};

#endif // MATCH_H
