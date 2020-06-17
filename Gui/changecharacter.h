#ifndef CHANGECHARACTER_H
#define CHANGECHARACTER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include "contenitore.h"


class ChangeCharacter: public QWidget{
    Q_OBJECT
private:
    QLabel * nome;
    QLabel * tipo;
    QLabel * livello;
    QLabel * health;
    QPushButton * assolda;

public:
    ChangeCharacter(){}
    ChangeCharacter(Contenitore squadra, QWidget *parent);
    QGroupBox* addLayoutPersonaggio(Contenitore);
public slots:
    void handleButton();


signals:
    void assoldaBtn(QString);
};

#endif // CHANGECHARACTER_H
