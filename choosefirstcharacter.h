#ifndef CHOOSEFIRSTCHARACTER_H
#define CHOOSEFIRSTCHARACTER_H

#include "mainwindow.h"

class ChooseFirstCharacter: public QWidget{
    Q_OBJECT

public:
    ChooseFirstCharacter(QWidget* parent=0);
    virtual ~ChooseFirstCharacter();

    virtual void handleButton();

};

#endif // CHOOSEFIRSTCHARACTER_H
