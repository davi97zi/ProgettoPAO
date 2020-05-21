#include "choosecharacter.h"
//#include "ui_choosecharacter.h"

chooseCharacter::chooseCharacter(QWidget *parent) :
    QWidget(parent)
{
    window = new QWidget();

    titolo = new QLabel("Scegli il personaggio");
    titolo->setAlignment(Qt::AlignTop);

    //contenitore

}
