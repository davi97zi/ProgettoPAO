#ifndef CHANGECHARACTER_H
#define CHANGECHARACTER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class ChangeCharacter: public QWidget{
    Q_OBJECT
private:
    QWidget* changeCharacterWindow;
    QGridLayout* gridLayout1;
    QLabel* titolo;
    QVBoxLayout* vlEx;
    QLabel* labelNome;
    QLabel* labelTipo;
    QPushButton* scegli;

public:
    ChangeCharacter(QWidget* parent=0);

    void handleButton();
};

#endif // CHANGECHARACTER_H
