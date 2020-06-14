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
    QPushButton* baseAttackBtn;
    QPushButton* abilita1;
    QPushButton* abilita2;
    QPushButton* abilita3;
    //Personaggio* p;

public:
    StatisticheMatchPersonaggio(int h, int ba, int a, QString n, int l, int m, QWidget* parent=0);
    QGridLayout* getAbilities();

public slots:
    void handleButton();
    void setArmor(int);
    void setHealth(int);
    void setMana(int);

signals:
    void eseguiAbilita(QString);
    void cambiaPersonaggioBtn();
};

#endif // STATISTICHEMATCHPERSONAGGIO_H
