#include "controller.h"
#include <QDebug>

#include "../gui/choosefirstcharacter.h"
#include "../gui/storico.h"


/*StoricoModello::StoricoModelloItem Controller::getStoricoRow(int i){
    return s->getPartita(i);
}*/

Controller::Controller(QObject *parent) : QObject(parent){
    //crea la finestra
    mw= new MainWindow();//serve this?

    //mostra finestra
    mw->show();

    //reagisce al click di un bottone: storico o partita?
    connect(mw, SIGNAL (signalBottone(QString)),this, SLOT (slotQualeBottone(QString)));

}

void Controller::slotQualeBottone(QString str){
    //qDebug() << s;

    if(str=="gioca"){
        ChooseFirstCharacter* cfc= new ChooseFirstCharacter();
        mw->setCentralWidget(cfc);

    }
    else{
        //storico
        //1) recupera i dati
        sMod= new StoricoModello();

        qDebug() <<"MY SIZE IS " << sMod->getSize();

        //vai alla schermata storico
        Storico* storicoGui= new Storico();
        // ????
        //connect(mw, SIGNAL (returnToMain()),this, SLOT (remakeMain()));
        //???
        //2) inserisci i dati nella gui
        //per ogni riga della tabella passa: data, battaglia, #personaggi, monete e risultato
        for(int i =0; i < (sMod->getSize()); i++){
            storicoGui->addRow(sMod->getPartita(i));
        }

        //mostra lo storico completo
        mw->setCentralWidget(storicoGui);

    }
}
