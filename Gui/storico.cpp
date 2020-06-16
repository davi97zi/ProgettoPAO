#include "storico.h"
#include <QMessageBox>
#include <QAbstractItemView>
#include <QDateTime>
#include <QStandardItemModel>
#include <QDebug>
#include "xml/xmlitem.h"

//#include "storicorow.h"

#include "../xml/storicoModello.h"

Storico::Storico(QWidget* parent): QWidget(parent){
    //windowStorico = new QWidget();

    vertical = new QVBoxLayout();

    titolo = new QLabel("Storico");
    titolo->setObjectName("titolo");

    titolo->setStyleSheet("QLabel#titolo{font-size: 20px; font-weight: bold; padding: 0.5em; margin: 0.5em;}");

    titolo->setAlignment(Qt::AlignTop);
    titolo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    //sostituisco la table
    table = new QTableWidget(this);
    //table->setRowCount(5); //numero di righe prese dal file = numero partite giocate
    table->setColumnCount(6);
    table->setShowGrid(true);


    //si possono selezionare solo le righe -> probabilmente inutile
    //table->setSelectionMode(QAbstractItemView::SingleSelection);
    //table->setSelectionBehavior(QAbstractItemView::SelectRows);

    //header table
    QStringList tableHeader;
    tableHeader<< "Data" << "Livello" << "#Personaggi" << "Monete" << "Risultato" << "Altro";
    table->setHorizontalHeaderLabels(tableHeader);

    //table->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //table->resize(1000, 1000);
    // IL BOTTONE VIENE STAMPATO SOLO NELL'ULTIMA RIGA


    indietro= new QPushButton("indietro");
    indietro->setObjectName("indietro");
    indietro->resize(165, 165);

    //tornare al main
    connect(indietro, SIGNAL (released()), this, SLOT (returnToMain()));

    vertical->addWidget(titolo, 0, Qt::AlignCenter);

    vertical->addWidget(indietro, 0, Qt::AlignLeft);

    vertical->addWidget(table);

    //vertical->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(vertical);
    //windowStorico->show();
}

void Storico::addRow(const StoricoModello::StoricoModelloItem & row){
    int i= row.StoricoModello::StoricoModelloItem::getId();
    qDebug() << "PersonaggioRow" << i << " rowcount " << QString::number(table->rowCount());
    //row.stampaStoricoModelloItem();
    //qDebug() << row.StoricoModello::StoricoModelloItem::getData();
    //qDebug() << row.StoricoModello::StoricoModelloItem::getBattaglia();
    //qDebug() << row.StoricoModello::StoricoModelloItem::getSizeSquadra();
    //qDebug() << row.StoricoModello::StoricoModelloItem::getOro();
    //qDebug() << row.StoricoModello::StoricoModelloItem::getVittoria();
    //qDebug() << "PersonaggioRow" << i << " DONE";

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

    //resize colums to contents
    table->resizeColumnsToContents();

}

//slots
void Storico::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    int row = button->objectName().toInt();
    qDebug() << button->objectName() << " " << row;
    emit showRowInfo(row);
    //controller: aprimi questa riga
    //emit SegnaleDaDefinire(i);// arriva al controller
}

void Storico::returnToMain(){
    qDebug() << "Im returnToMain";
    emit signalReturnToMain();
}

