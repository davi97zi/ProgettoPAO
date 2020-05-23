#ifndef MATCH_H
#define MATCH_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "abilita_personaggio_match.h"
#include "info_match.h"
#include "statistichematch.h"

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
    Match(QWidget* parent=0);
};

#endif // MATCH_H
