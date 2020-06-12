#ifndef MATCH_H
#define MATCH_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "abilita_personaggio_match.h"
#include "info_match.h"
#include "statistichematchmostro.h"
#include "statistichematchpersonaggio.h"

class Match: public QWidget{
    Q_OBJECT
private:
    QWidget* window;
    QVBoxLayout* contenitore;
    QGridLayout* layoutMostro;
    QGridLayout* layoutPersonaggio;
    QLabel* turno;
    QLabel* coins;

public:
    Match(StatisticheMatchMostro* smm, StatisticheMatchPersonaggio* smp, int t, int m, QWidget* parent=0);
};

#endif // MATCH_H
