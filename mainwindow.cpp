#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

#include "storico.h"
#include "choosefirstcharacter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //container della prima finestra
    QWidget* firstWindow = new QWidget;

    QPushButton* gioca = new QPushButton("Gioca", this);
    QPushButton* storico = new QPushButton("Storico", this);
    QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    QVBoxLayout* verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(gioca);
    verticalLayout1->addItem(spacer);
    verticalLayout1->addWidget(storico);

    connect(gioca, SIGNAL (released()),this, SLOT (handleButton()));
    connect(storico, SIGNAL (released()),this, SLOT (handleButton()));

    firstWindow->setLayout(verticalLayout1);
    setCentralWidget(firstWindow);
    firstWindow->show();
}

void MainWindow::handleButton(){
    //QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QPushButton* button = (QPushButton*)sender();
    if(button->objectName()=="gioca"){
        //vai alla schermata chooseFirstCharacter
        ChooseFirstCharacter* cfc;
        cfc->show();
    } else if(button->objectName()=="storico"){
        //vai alla schermata storico
        Storico* s;
        s->show();
    }
}

MainWindow::~MainWindow()
{
    delete this;
}
