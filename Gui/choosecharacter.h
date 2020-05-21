#ifndef CHOOSECHARACTER_H
#define CHOOSECHARACTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class chooseCharacter : public QWidget
{
    Q_OBJECT

private:
    QWidget* window;
    QLabel* titolo;
    QPushButton scegli;

public:
    chooseCharacter(QWidget *parent = 0);
};

#endif // CHOOSECHARACTER_H
