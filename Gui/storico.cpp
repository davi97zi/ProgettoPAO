#include "storico.h"
#include <QMessageBox>
#include <QAbstractItemView>
#include <QDateTime>
#include <QStandardItemModel>

Storico::Storico(QWidget* parent): QWidget(parent){
    windowStorico = new QWidget();

    vertical = new QVBoxLayout();

    titolo = new QLabel("Storico");
    titolo->setAlignment(Qt::AlignTop);
    titolo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    table = new QTableWidget(this);
    table->setRowCount(getFileRows()); //numero di righe prese dal file = numero partite giocate
    table->setColumnCount(6);
    table->setShowGrid(true);

    //si possono selezionare solo le righe -> probabilmente inutile
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    //header table
    QStringList tableHeader;
    tableHeader<< "Data" << "Livello" << "#Personaggi" << "Monete" << "Risultato" << "Altro";
    table->setHorizontalHeaderLabels(tableHeader);

    //btn per ottenere piu informazioni riguardo al game scelto
    moreInfo = new QPushButton("More info");
    moreInfo->setParent(table);
    moreInfo->setVisible(true);

    //Meglio fare una funzione?
    //add items to table -> serve la lunghezza del file (in base al numero di partite) -> getFileRows()
    for(int i=0; i<getFileRows(); i++){
        //insert row
        table->insertRow(i);
        //nella posizione 0 dovrebbe esserci l'id generato in automatico
        table->setItem(i, 1, new QTableWidgetItem(getDate()->toString()));
        table->setItem(i, 2, new QTableWidgetItem());//getLivello dal file -> toString())) dentro il tablewidgetitem
        table->setItem(i, 3, new QTableWidgetItem());//getNumPersonaggi dal file QString::number(getNumpersonaggi))) dentro il tablewidgetitem
        table->setItem(i, 4, new QTableWidgetItem());//getMonete dal file QString::number(getMonete))) dentro il tablewidgetitem
        table->setItem(i, 5, new QTableWidgetItem());//getRisultato dal file -> toString())) dentro il tablewidgetitem
        table->setCellWidget(i, 6, dynamic_cast<QWidget*>(moreInfo));
        //bisogna associare il btn all'id della partita corrispondente?
    }

    //resize colums to contents
    table->resizeColumnsToContents();

    connect(moreInfo, SIGNAL (released()),this, SLOT (handleButton()));

    vertical->addWidget(titolo);
    vertical->addWidget(table);

    windowStorico->setLayout(vertical);
    windowStorico->show();
}

//ritorna la data odierna
QDate* Storico::getDate(){
    QDate* today = new QDate(QDate::currentDate());
    return today;
}

//ritorna il numero di righe prese dal file
int Storico::getFileRows(){

}

void Storico::handleButton(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender()); //QPushButton* button = (QPushButton*)sender();
    if(button->objectName() == "moreInfo"){
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setText("You selected a specific game.");
        msgBox->setInformativeText("Do you want to see more informations about the game you clicked?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::Yes);
        msgBox->setEscapeButton(QMessageBox::No);

        int ret = msgBox->exec();

        switch (ret) {
          case QMessageBox::Yes:
              // Yes was clicked -> si crea il btn Show Details che se cliccato mostra piu info nello stesso QMessageBox
              //qua bisogna prendersi le info dal file

            /* The detailed text property is always interpreted as plain text.
             * The main text and informative text properties can be either plain text or rich text.
             * These strings are interpreted according to the setting of the text format property. The default setting is auto-text.
             * Note that for some plain text strings containing XML meta-characters, the auto-text rich text detection test may fail
             * causing your plain text string to be interpreted incorrectly as rich text.
             * In these rare cases, use Qt::convertFromPlainText() to convert your plain text string to a visually equivalent rich text string,
             * or set the text format property explicitly with setTextFormat().
             */
              msgBox->setDetailedText("Turni giocati: " + turni +
                                   "Monete guadagnate: " + monete +
                                   "Personaggi comprati: " + personaggio);
              break;
          case QMessageBox::No:
             // No was clicked
              msgBox->close();
              break;
          default:
              // should never be reached
              break;
        }
    }
}
