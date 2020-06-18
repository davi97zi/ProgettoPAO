#ifndef CHANGE_CHARACTER_H
#define CHANGE_CHARACTER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
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

#endif // CHANGE_CHARACTER_H
