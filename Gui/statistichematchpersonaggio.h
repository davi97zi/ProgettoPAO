#ifndef STATISTICHEMATCHPERSONAGGIO_H
#define STATISTICHEMATCHPERSONAGGIO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "../Interfacce/personaggio.h"

class StatisticheMatchPersonaggio: public QWidget{
    Q_OBJECT
private:
    QHBoxLayout* tot;
    QGridLayout* stats;
    QGridLayout* info;
    QLabel* titolo;
    QLabel* health;
    QLabel* baseAttack;
    QLabel* mana;
    QLabel* armor;

    QPushButton* cambiaPersonaggio;

    //Personaggio* p;

public:
    StatisticheMatchPersonaggio(QWidget* parent=0);
    QGridLayout* getAbilities();
    void handleButton();
};

#endif // STATISTICHEMATCHPERSONAGGIO_H
