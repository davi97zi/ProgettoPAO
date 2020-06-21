#include "change_character.h"

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
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
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
        nome->setStyleSheet("QLabel{color: red}");
        tipo->setStyleSheet("QLabel{color: red}");
        health->setStyleSheet("QLabel{color: red}");
        livello->setStyleSheet("QLabel{color: red}");
        assolda->setVisible(false);
    }
    assolda->setObjectName(QString::number(i));

    connect(assolda, SIGNAL(released()), this, SLOT(handleButton()));

    groupLay->addWidget(nome, 0, Qt::AlignCenter);
    groupLay->addWidget(tipo, 0, Qt::AlignCenter);
    groupLay->addWidget(health, 0, Qt::AlignCenter);
    groupLay->addWidget(livello, 0, Qt::AlignCenter);
    groupLay->addWidget(assolda, 0, Qt::AlignCenter);

    scheda->setLayout(groupLay);
    return scheda;
}
