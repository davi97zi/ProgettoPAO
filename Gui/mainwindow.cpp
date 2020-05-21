#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "storico.h"
#include "choosefirstcharacter.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    //container della prima finestra
    firstWindow = new QWidget();

    gioca = new QPushButton("Gioca", this);
    storico = new QPushButton("Storico", this);
    spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(gioca);
    verticalLayout1->addItem(spacer);
    verticalLayout1->addWidget(storico);

    connect(gioca, SIGNAL (released()),this, SLOT (handleButton()));
    connect(storico, SIGNAL (released()),this, SLOT (handleButton()));

    firstWindow->setLayout(verticalLayout1);
    firstWindow->show();
}

void MainWindow::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    //QPushButton* button = (QPushButton*)sender();
    if(button->objectName()=="gioca"){
        //vai alla schermata chooseFirstCharacter
        ChooseFirstCharacter* cfc;
        cfc->show();
    } else if(button->objectName()=="storico"){
        //vai alla schermata storico
        Storico* s;
        s->show();
    }
    firstWindow->close();
}
