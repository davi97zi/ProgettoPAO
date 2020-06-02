#ifndef STATISTICHEMATCH_H
#define STATISTICHEMATCH_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "../Interfacce/personaggio.h"

class StatisticheMatchMostro: public QWidget{
    Q_OBJECT
private:
    QHBoxLayout* tot;
    QGridLayout* stats;
    QGridLayout* info;
    QHBoxLayout* img;
    QLabel* titolo;
    QLabel* health;
    QLabel* baseAttack;
    QLabel* mana;
    QLabel* armor;

    //QPushButton* cambiaPersonaggio;

    //Personaggio* p;

public:
    StatisticheMatchMostro(QWidget* parent=0);

   // void handleButton();
};

#endif // STATISTICHEMATCH_H
