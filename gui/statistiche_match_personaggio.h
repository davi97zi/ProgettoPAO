#ifndef STATISTICHE_MATCH_PERSONAGGIO_H
#define STATISTICHE_MATCH_PERSONAGGIO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QToolButton>
#include "../interfacce/personaggio.h"
#include "../personaggi/mago.h"
#include "../personaggi/artificiere.h"
#include "abilita_personaggio_match.h"
#include "change_character.h"

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
    QLabel* personaggio;
    QLabel* livelloP;
    QPushButton* cambiaPersonaggio;
    QPushButton* baseAttackBtn;
    QPushButton* abilita1;
    QPushButton* abilita2;
    QPushButton* abilita3;
    //Personaggio* p;

public:
    StatisticheMatchPersonaggio(){}
    StatisticheMatchPersonaggio(int h, int ba, int a, QString n, int l, int m, QWidget* parent=0);
    QGridLayout* getAbilities();

public slots:
    void handleButton();
    void setBa(int);
    void setArmor(int);
    void setHealth(int);
    void setMana(int);
    void setNome(QString n);
    void setLivello(int);

signals:
    void eseguiAbilita(QString);
    void cambiaPersonaggioBtn(QString);
};

#endif // STATISTICHE_MATCH_PERSONAGGIO_H
