#ifndef CHOOSEFIRSTCHARACTER_H
#define CHOOSEFIRSTCHARACTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <QGridLayout>
#include <QSizePolicy>


class ChooseFirstCharacter: public QWidget{
    Q_OBJECT
private:
    QWidget* chooseCharacterWindow;
    QLabel* titolo;
    QLabel* nome;
    QLabel* tipo;
    QPushButton* scegli;
    QSpacerItem* spacer;
    QVBoxLayout* verticalLayout1;
public:
    ChooseFirstCharacter(QWidget* parent=0);

    virtual void handleButton();
    QVBoxLayout* personaggio1();
    QVBoxLayout* personaggio2();
    QVBoxLayout* personaggio3();

};

#endif // CHOOSEFIRSTCHARACTER_H
