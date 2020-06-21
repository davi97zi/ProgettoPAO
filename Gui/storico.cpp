#include "storico.h"


Storico::Storico(QWidget* parent): QWidget(parent){

    vertical = new QVBoxLayout();

    titolo = new QLabel("Storico");
    titolo->setObjectName("titolo");

    titolo->setStyleSheet("QLabel#titolo{font-size: 20px; font-weight: bold; padding: 0.5em; margin: 0.5em;}");

    titolo->setAlignment(Qt::AlignTop);
    titolo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    //sostituisco la table
    table = new QTableWidget(this);
    table->setColumnCount(6);
    table->setShowGrid(true);

    //header table
    QStringList tableHeader;
    tableHeader<< "Data" << "Livello" << "#Personaggi" << "Monete" << "Risultato" << "Altro";
    table->setHorizontalHeaderLabels(tableHeader);

    indietro= new QPushButton("indietro");
    indietro->setObjectName("indietro");
    indietro->resize(165, 165);

    //tornare al main
    connect(indietro, SIGNAL (released()), this, SLOT (returnToMain()));

    vertical->addWidget(titolo, 0, Qt::AlignCenter);
    vertical->addWidget(indietro, 0, Qt::AlignLeft);
    vertical->addWidget(table);

    setLayout(vertical);

}

void Storico::addRow(const StoricoModello::StoricoModelloItem & row){
    int i= static_cast<int>(row.StoricoModello::StoricoModelloItem::getId());


    table->insertRow(i);
    table->setItem(i, 0, new QTableWidgetItem(row.StoricoModello::StoricoModelloItem::getData()));
    table->setItem(i, 1, new QTableWidgetItem(row.StoricoModello::StoricoModelloItem::getBattaglia()));
    table->setItem(i, 2, new QTableWidgetItem(QString::number(row.StoricoModello::StoricoModelloItem::getSizeSquadra())));
    table->setItem(i, 3, new QTableWidgetItem(row.StoricoModello::StoricoModelloItem::getOro()));
    table->setItem(i, 4, new QTableWidgetItem(row.StoricoModello::StoricoModelloItem::getVittoria()));
    //btn per ottenere piu informazioni riguardo al game scelto
    QPushButton * moreInfo = new QPushButton("More info");
    moreInfo->setObjectName(QString::number(i));
    connect(moreInfo, SIGNAL (released()),this, SLOT (handleButton()));
    table->setCellWidget(i, 5, moreInfo);

    table->resizeColumnsToContents();

}

//slots
void Storico::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    int row = button->objectName().toInt();
    emit showRowInfo(row);
}

void Storico::returnToMain(){
    emit signalReturnToMain();
}

