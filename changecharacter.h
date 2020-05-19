#ifndef CHANGECHARACTER_H
#define CHANGECHARACTER_H

#include <QObject>
#include <mainwindow.h>

class ChangeCharacter: public QWidget{
    Q_OBJECT

public:
    ChangeCharacter(QWidget* parent=0);
    virtual ~ChangeCharacter();

    virtual void handleButton();
};

#endif // CHANGECHARACTER_H
