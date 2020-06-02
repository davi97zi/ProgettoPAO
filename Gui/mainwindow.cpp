#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "storico.h"
#include "choosefirstcharacter.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) //corretto?
{
    //container della prima finestra
    firstWindow = new QWidget();

    gioca = new QPushButton("Gioca", this);
    gioca->setObjectName("gioca");
    storico = new QPushButton("Storico", this);
    storico->setObjectName("storico");
    spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(gioca);
    verticalLayout1->addItem(spacer);
    verticalLayout1->addWidget(storico);


    connect(gioca, SIGNAL (released()),this, SLOT (handleButton()));
    connect(storico, SIGNAL (released()),this, SLOT (handleButton()));



    firstWindow->setLayout(verticalLayout1);

    setCentralWidget(firstWindow);

    resize(1000, 1000);//da modificare?
}

void MainWindow::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if(button->objectName()=="gioca"){
        //vai alla schermata chooseFirstCharacter
        //ChooseFirstCharacter* cfc= new ChooseFirstCharacter();
        //firstWindow= cfc;
        //setCentralWidget(firstWindow);
        emit signalBottone("gioca");
        //cfc->show();
    } else if(button->objectName()=="storico"){
        //vai alla schermata storico
        //Storico* s= new Storico();
        //firstWindow=s;
        //setCentralWidget(firstWindow);

        // ????
        connect(firstWindow, SIGNAL (returnToMain()),this, SLOT (remakeMain()));
        //???

        emit signalBottone("storico");
        //s->show();
    }
    //in ogni caso chiudo la finestra
    //firstWindow->close();
}

void MainWindow::remakeMain(){
    //firstWindow->close();
    qDebug() << "I GOT HERE????";
    //riporta a vecchia finestra principale vedremo come dopo

}
