#ifndef STATISTICHE_MATCH_MOSTRO_H
#define STATISTICHE_MATCH_MOSTRO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include "../interfacce/personaggio.h"
#include "../personaggi/mago.h"
#include "../personaggi/artificiere.h"
#include "change_character.h"

class StatisticheMatchMostro: public QWidget{
    Q_OBJECT

private:
    QHBoxLayout* tot;
    QGridLayout* stats;
    QGridLayout* info;
    QHBoxLayout* ex;
    QLabel* experience;
    QLabel* titolo;
    QLabel* health;
    QLabel* baseAttack;
    QLabel* nomeMostro;
    QLabel* livelloMostro;
    QLabel* armor;

public:
    StatisticheMatchMostro(int h, int ba, int a, QString n, int l, int exp, QWidget* parent=0);

public slots:
    void setHealth(int);

};

#endif // STATISTICHE_MATCH_MOSTRO_H
