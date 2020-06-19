#include "change_character.h"
#include <QDebug>

//verosimile che controller si occupi di passare questi dati? y, in this way? idk we will see
ChangeCharacter::ChangeCharacter(Contenitore squadra, QWidget *parent) : QWidget(parent){
    resize(500,350);
    QVBoxLayout * lay= new QVBoxLayout();
    int i=0;
    for(auto it=squadra.begin(); it!=squadra.end(); ++it){
        lay->addWidget(addLayoutPersonaggio(*it, i));
        i++;
    }
    setLayout(lay);
}

void ChangeCharacter::handleButton(){
    //QPushButton* button = dynamic_cast<QPushButton*>(sender());
    qDebug() << "1) è partito l'assoldaBtn da changecharacter";
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    qDebug()<< button->objectName();
    emit assoldaBtn(button->objectName());
}

QGroupBox* ChangeCharacter::addLayoutPersonaggio(const Personaggio& it, int i){
    QGroupBox * scheda= new QGroupBox("Personaggio" + QString::number(i));
    QVBoxLayout * groupLay= new QVBoxLayout();
    nome= new QLabel("Nome: " + QString::fromStdString(it.getNome()));
    tipo= new QLabel("Tipo: " + QString::fromStdString(it.getTipoPersonaggio()));
    livello= new QLabel("Livello: " + QString::number(it.getLevel()));
    health= new QLabel("Health: " + QString::number(it.getHealth()));
    assolda= new QPushButton("Scegli");
    if(it.getHealth() == 0){
        //assolda= new QPushButton("Scegli");
        nome->setStyleSheet("QLabel{color: red}");
        tipo->setStyleSheet("QLabel{color: red}");
        health->setStyleSheet("QLabel{color: red}");
        livello->setStyleSheet("QLabel{color: red}");
        assolda->setVisible(false);
    }
    //gli dò un objName
    assolda->setObjectName(QString::number(i));
    //conect: quale bottone ho cliccato?= quale personaggio ho scelto
    connect(assolda, SIGNAL(released()), this, SLOT(handleButton()));

    groupLay->addWidget(nome, 0, Qt::AlignCenter);
    groupLay->addWidget(tipo, 0, Qt::AlignCenter);
    groupLay->addWidget(health, 0, Qt::AlignCenter);
    groupLay->addWidget(livello, 0, Qt::AlignCenter);
    groupLay->addWidget(assolda, 0, Qt::AlignCenter);

    //groupLay->addStretch(1);
    scheda->setLayout(groupLay);
    return scheda;
}
