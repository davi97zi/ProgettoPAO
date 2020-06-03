#include "scegliapplicativo.h"
#include <QDebug>

ScegliApplicativo::ScegliApplicativo(QWidget *parent) : QWidget(parent)
{
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

    setLayout(verticalLayout1);

    resize(1000, 1000);//da modificare?
}

void ScegliApplicativo::handleButton(){
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
        //connect(this, SIGNAL (returnToMain()),this, SLOT (remakeMain()));
        //???

        emit signalBottone("storico");
        //s->show();
    }
    //in ogni caso chiudo la finestra
    //firstWindow->close();
}

void ScegliApplicativo::remakeMain(){
    //firstWindow->close();
    qDebug() << "I GOT HERE????";
    //riporta a vecchia finestra principale vedremo come dopo

}
