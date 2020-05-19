#ifndef ABILITA_PERSONAGGIO_MATCH_H
#define ABILITA_PERSONAGGIO_MATCH_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class AbilitaPersonaggioMatch: public QWidget{
    Q_OBJECT
private:
    QLabel* titolo;
    QPushButton* baseAttack;
    QPushButton* abilita1;
    QPushButton* abilita2;
    QPushButton* abilita3;

    QGridLayout* abilita;
    QGridLayout* abilitaEsterno; //contiene QGridLayout abilita

public:
    AbilitaPersonaggioMatch(QWidget* parent=0);

    void handleButton();
};

#endif // ABILITA_PERSONAGGIO_MATCH_H
