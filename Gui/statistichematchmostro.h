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
    QLabel* nomeMostro;
    QLabel* livelloMostro;
    //QLabel* mana;
    QLabel* armor;

    //QPushButton* cambiaPersonaggio;

    //Personaggio* p;

public:
    StatisticheMatchMostro(int h, int ba, int a, QString n, int l, QWidget* parent=0);

    /*void setHealth(int);
    void setBaseAttack(int);
    void setArmor(int);
    void setNome(QString);
    void setNome(QString);*/

   // void handleButton();
};

#endif // STATISTICHEMATCH_H
