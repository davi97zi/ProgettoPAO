#include "controller.h"
#include <QDebug>

#include "../Gui/negozio_widget.h"
#include "../Gui/storico.h"
#include "xml/storicoModello.h"
#include "xml/taverna.h"
#include "../Gui/infopartitastorico.h"
#include "../Gui/match.h"
#include "../xml/dungeon.h"
#include "../Gui/statistichematchmostro.h"
#include "../Gui/statistichematchpersonaggio.h"

/*StoricoModello::StoricoModelloItem Controller::getStoricoRow(int i){
    return s->getPartita(i);
}*/

void Controller::eseguiAbilita(int abilita, bool terza){
    if(abilita<0){ //è un attacco
        qDebug() << "è un attacco, danno: " << abilita;
        pMod->attaccaMostro(abilita);
        emit updatedHPMostro(pMod->getHealthMostro());
    }
    else{//è una guarigione o un buff
        if(abilita==0){//buff fallito?
            //throw ("errore buff fallito");    ???
            qDebug() << "errore buff fallito";
        }
        else if(abilita==1){
            qDebug() << "è un buff";
            emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
        }
        else{//guarigione
            if(!terza){
                qDebug() << "è una guarigione";
                pMod->guarisciTutti(abilita);

            }
            else{
                qDebug() << "è un miracolo";
                pMod->resuscita(abilita);
                //qdialog: "hai resuscitato i tuoi morti!"
            }
            emit updatedHealthPersonaggio(pMod->getHealthPersonaggio());
        }

    }
    //fine turno giocatore
    //inizia turno computer
}

Controller::Controller(QObject *parent) : QObject(parent){
    //evitiamo segmentation fault
    pMod= nullptr;
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

void Controller::creaMatch(){
    StatisticheMatchMostro* smm = new StatisticheMatchMostro(pMod->getHealthMostro(), pMod->getBAMostro(), pMod->getArmorMostro(), pMod->getNomeMostro(), pMod->getLivelloMostro(), pMod->getExpMostro());
    StatisticheMatchPersonaggio* smp = new StatisticheMatchPersonaggio(pMod->getHealthPersonaggio(), pMod->getBAPersonaggio(), pMod->getArmorPersonaggio(), pMod->getNomePersonaggio(), pMod->getLivelloPersonaggio(), pMod->getManaPersonaggio());
    Match* m = new Match(smm, smp, pMod->getRound(), pMod->getMonete());
    mw->setCentralWidget(m);
    qDebug() << "Controller::creaMatch entra";
    //prende bottone cliccato sezione abilita personaggio
    connect(mw->centralWidget(), SIGNAL(eseguiAbilitaP(QString)), this, SLOT(getAction(QString)));

    //manda a match il danno al mostro
    connect(this, SIGNAL(updatedHPMostro(int)), smm, SLOT(setHealth(int)));

    //manda a match il cambiamento di armor (pers)
    connect(this, SIGNAL(updatedArmPersonaggio(int)), smp, SLOT(setArmor(int)));

    //manda a match il cambiamento di vita (pers)
    connect(this, SIGNAL(updatedHealthPersonaggio(int)), smp, SLOT(setHealth(int)));

    qDebug() << "Controller::creaMatch esce";
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

    getMostro(pMod->getRound()-1);
    creaMatch();
}

void Controller::getMostro(int i){
    Dungeon mostro;
    pMod->cambiaMostro(mostro.challengeMonster(i));
}

//personaggio action (da match window)
void Controller::getAction(QString a) try{
    if(a == "baseAttack"){
        int baPersonaggio = pMod->getBAPersonaggio()*(-1);
        pMod->attaccaMostro(baPersonaggio);
        //aggiungere QDialog
        qDebug() << "Controller::getAction" << "Vita: " << pMod->getHealthMostro() << "Danno: " << baPersonaggio;
        emit updatedHPMostro(pMod->getHealthMostro());
    }
    else if (a == "abilita1"){
        int abilita1Personaggio = pMod->getAbilita1();
        eseguiAbilita(abilita1Personaggio, false);
    }
    else if (a == "abilita2"){
        qDebug() << a;
        int abilita2Personaggio = pMod->getAbilita2();
        eseguiAbilita(abilita2Personaggio, false);
    }
    else {
        qDebug() << a;
        int abilita3Personaggio = pMod->getAbilita3();
        if(pMod->getTurnoA3()!=0){
            pMod->setTurniA3(-1);
            if(pMod->getTurnoA3()==0){
                pMod->resetArmor();
                emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
            }
        }else{
        eseguiAbilita(abilita3Personaggio, true);
        pMod->setTurniA3(3);
        }
    }
//mago dice che fa meno danno di quello effettivo
}catch(int){

}


//se abilita fa danni (danno > 0) -> danno normale
//altrimenti richiama funzione particolare che fa quello che deve fare
