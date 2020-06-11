#include "controller.h"
#include <QDebug>

#include "../Gui/negozio_widget.h"
#include "../Gui/storico.h"
#include "xml/storicoModello.h"
#include "xml/taverna.h"
#include "../Gui/infopartitastorico.h"

/*StoricoModello::StoricoModelloItem Controller::getStoricoRow(int i){
    return s->getPartita(i);
}*/

Controller::Controller(QObject *parent) : QObject(parent){
    //evitiamo segmentation fault
    pMod=nullptr;
    sMod= nullptr;

    //crea la finestra
    mw= new MainWindow();//serve this?

    remakeMain();

    //mostra finestra
    mw->show();

    //reagisce al click di un bottone: storico o partita?
    //DA METTERE FORSE IN SCEGLIAPPLICATIVO ??????

}

void Controller::slotQualeBottone(QString str){
    //qDebug() << s;

    if(str=="gioca"){
        //creo taverna e trovo personaggi di liv 1
        Taverna fandolin;
        std::vector<XmlItem> assoldabili= fandolin.trovaTuttiLivello(1);

        //creo il negozio x scegliere primo personaggio (inizio= true)
        Negozio_widget * negozio= new Negozio_widget(assoldabili, true);
        mw->setCentralWidget(negozio);

        //creo connect clicco uno degli scegli: voglio sapere quale
        connect(mw->centralWidget(), SIGNAL(personaggioAcquistato(int)), this, SLOT(creaPersonaggio(int)));


    }
    else{
        //storico
        //1) recupera i dati
        sMod= new StoricoModello();

        qDebug() <<"MY SIZE IS " << sMod->getSize();

        //vai alla schermata storico
        Storico* storicoGui= new Storico();

        //return alla scegliApplicativo
        connect(storicoGui, SIGNAL (signalReturnToMain()), this, SLOT (remakeMain()));

        //2) inserisci i dati nella gui
        //per ogni riga della tabella passa: data, battaglia, #personaggi, monete e risultato
        for(int i=0; i < sMod->getSize(); i++){
            storicoGui->addRow(sMod->getPartita(i));
        }

        connect(storicoGui, SIGNAL (showRowInfo(int)), this, SLOT (stampaRowInfo(int)));

        //mostra lo storico completo
        mw->setCentralWidget(storicoGui);

    }
}
void Controller::remakeMain(){
    //firstWindow->close();
    qDebug() << "Controller::remakeMain()";
    mw->resetCentralWidget();
    connect(mw->centralWidget(), SIGNAL (signalBottone(QString)),this, SLOT (slotQualeBottone(QString)));
}

void Controller::stampaRowInfo(int i){
    StoricoModello::StoricoModelloItem partitaMod = sMod->getPartita(i);
    InfoPartitaStorico * partitaGui= new InfoPartitaStorico;
    qDebug() << "size squadra: " << partitaMod.getSizeSquadra();
    for(int k=0; k<partitaMod.getSizeSquadra(); k++){
        QString nome= partitaMod.getAvv(k).getNome(),
                tipo= partitaMod.getAvv(k).getTipo(),
                livello= QString::number(partitaMod.getAvv(k).getLivello());
        partitaGui->addPersonaggio(nome, tipo, livello, k+1);
    }
    partitaGui->show();
}

void Controller::creaPersonaggio(int i){
    qDebug() << "3)voglio inserire " << i << " nel mio party";
    //Queste 2 righe potrebbero dover andare in partita
    Taverna fandolin;

    std::vector<XmlItem> assoldabili= fandolin.trovaTuttiLivello(1);//bisogna sistemare per i livelli
    XmlItem base=assoldabili[i];
    if(pMod==0)
        pMod=new Partita(base.convertiInPersonaggio());
    else
        pMod->aggiungiPersonaggio(base.convertiInPersonaggio());
    pMod->stampaSquadra();
}
