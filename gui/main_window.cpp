#include "main_window.h"
#include <QDebug>


MainWindow::MainWindow(QWidget* central, QWidget *parent) : firstWindow(central),
    QMainWindow(parent)
{
    resize(500,350);

    connect(this, SIGNAL (signalReturnToMain()), this, SLOT (remakeMain()));

    setCentralWidget(firstWindow);
}

void MainWindow::resetCentralWidget(){
    setCentralWidget(new ScegliApplicativo);
}

/*
void MainWindow::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if(button->objectName()=="gioca"){
        //vai alla schermata chooseFirstCharacter
        //ChooseFirstCharacter* cfc= new ChooseFirstCharacter();
        //firstWindow= cfc;
        //setCentralWidget(firstWindow);
        //emit signalBottone("gioca");
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
}*/

/*void MainWindow::remakeMain(){
    //firstWindow->close();
    qDebug() << "I GOT HERE????";
    //riporta a vecchia finestra principale vedremo come dopo

}*/
