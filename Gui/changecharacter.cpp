#include "changecharacter.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDebug>

//verosimile che controller si occupi di passare questi dati? y, in this way? idk we will see
ChangeCharacter::ChangeCharacter(Contenitore squadra, QWidget *parent) : QWidget(parent){
    QVBoxLayout * lay= new QVBoxLayout();
    lay->addWidget(addLayoutPersonaggio(squadra));
    setLayout(lay);
}

void ChangeCharacter::handleButton(){
    //QPushButton* button = dynamic_cast<QPushButton*>(sender());
    qDebug() << "1) è partito l'assoldaBtn da changecharacter";
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    qDebug()<< button->objectName();
    emit assoldaBtn(button->objectName());
}

QGroupBox* ChangeCharacter::addLayoutPersonaggio(Contenitore c){
    int i=0;
    QGroupBox * scheda= new QGroupBox("Personaggio");
    QVBoxLayout * groupLay= new QVBoxLayout();
    for(auto it=c.begin(); it!=c.end(); ++it){
        nome= new QLabel(it->getNome());
        tipo= new QLabel(it->getTipoPersonaggio());
        livello= new QLabel(QString::number(it->getLevel()));
        health= new QLabel(QString::number(it->getHealth()));
        assolda= new QPushButton("Scegli");
        //gli dò un objName
        assolda->setObjectName(QString::number(i));
        //conect: quale bottone ho cliccato?= quale personaggio ho scelto
        connect(assolda, SIGNAL(released()), this, SLOT(handleButton()));
        i++;

        groupLay->addWidget(nome, 0, Qt::AlignCenter);
        groupLay->addWidget(tipo, 0, Qt::AlignCenter);
        groupLay->addWidget(health, 0, Qt::AlignCenter);
        groupLay->addWidget(livello, 0, Qt::AlignCenter);
        groupLay->addWidget(assolda, 0, Qt::AlignCenter);

        groupLay->addStretch(1);
    }
    scheda->setLayout(groupLay);
    return scheda;
}
