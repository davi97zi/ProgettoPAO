#include "controller.h"


void Controller::eseguiAbilita(int abilita, bool terza){
    if(abilita<0){ //è un attacco
        pMod->attaccaMostro(abilita);
        emit updatedHPMostro(pMod->getHealthMostro());
        emit updatedManaPersonaggio(pMod->getManaPersonaggio());
    }
    else{//è una guarigione o un buff
        if(abilita==1){//è un buff
            emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
        }
        else{//guarigione
            if(!terza){
                pMod->guarisciTutti(abilita);
            }
            else{
                pMod->resuscita(abilita);
            }
            emit updatedHealthPersonaggio(pMod->getHealthPersonaggio());
        }
    }
}

Controller::Controller(QObject *parent) : QObject(parent){
    pMod= nullptr;
    sMod= nullptr;
    smp = nullptr;
    //crea la finestra
    mw= new MainWindow();

    remakeMain();
    mw->show();
}

void Controller::slotQualeBottone(QString str){
    if(str=="gioca"){
        Taverna taverna;
        //creo taverna e trovo personaggi di liv 1
        std::vector<XmlItem> assoldabili= taverna.trovaTuttiLivello(1);

        //creo il negozio x scegliere primo personaggio (inizio= true)
        Negozio_widget* negozio= new Negozio_widget(assoldabili, 0, true);
        mw->setCentralWidget(negozio);

        //creo connect clicco uno degli scegli: voglio sapere quale
        connect(mw->centralWidget(), SIGNAL(personaggioAcquistato(int)), this, SLOT(creaPersonaggio(int)));
    }
    else{//storico
        sMod= new StoricoModello();

        Storico* storicoGui= new Storico();

        //return alla scegliApplicativo
        connect(storicoGui, SIGNAL (signalReturnToMain()), this, SLOT (remakeMain()));

        //inserisce i dati nella gui
        //per ogni riga della tabella passa: data, battaglia, #personaggi, monete e risultato
        for(unsigned int i=0; i < sMod->getSize(); i++){
            storicoGui->addRow(sMod->getPartita(i));
        }

        connect(storicoGui, SIGNAL (showRowInfo(int)), this, SLOT (stampaRowInfo(int)));

        //mostra lo storico completo
        mw->setCentralWidget(storicoGui);
    }
}

void Controller::remakeMain(){
    if(pMod){
        delete pMod;
        pMod=0;
    }
    mw->resetCentralWidget();
    connect(mw->centralWidget(), SIGNAL (signalBottone(QString)),this, SLOT (slotQualeBottone(QString)));
}

void Controller::stampaRowInfo(int i){
    StoricoModello::StoricoModelloItem partitaMod = sMod->getPartita(static_cast<unsigned int>(i));
    InfoPartitaStorico * partitaGui= new InfoPartitaStorico;
    for(int k=0; k<static_cast<int>(partitaMod.getSizeSquadra()); k++){
        QString nome= partitaMod.getAvv(k).getNome(),
                tipo= partitaMod.getAvv(k).getTipo(),
                livello= QString::number(partitaMod.getAvv(k).getLivello());
        partitaGui->addPersonaggio(nome, tipo, livello, k+1);
    }
    partitaGui->show();
}

void Controller::creaMatch(){
    StatisticheMatchMostro* smm = new StatisticheMatchMostro(pMod->getHealthMostro(), pMod->getBAMostro(), pMod->getArmorMostro(), QString::fromStdString(pMod->getNomeMostro()), pMod->getLivelloMostro(), pMod->getExpMostro());
    smp = new StatisticheMatchPersonaggio(pMod->getHealthPersonaggio(), pMod->getBAPersonaggio(), pMod->getArmorPersonaggio(), QString::fromStdString(pMod->getNomePersonaggio()), pMod->getLivelloPersonaggio(), pMod->getManaPersonaggio());
    Match* m = new Match(smm, smp, static_cast<int>(pMod->getRound()), pMod->getMonete());
    mw->setCentralWidget(m);

    connect(mw->centralWidget(), SIGNAL(eseguiAbilitaP(QString)), this, SLOT(getAction(QString)));
    connect(smp, SIGNAL(cambiaPersonaggioBtn(QString)), this, SLOT(getAction(QString)));

    //manda a match il danno al mostro
    connect(this, SIGNAL(updatedHPMostro(int)), smm, SLOT(setHealth(int)));

    //manda a match il cambiamento di armor (pers)
    connect(this, SIGNAL(updatedArmPersonaggio(int)), smp, SLOT(setArmor(int)));

    //manda a match il cambiamento di vita (pers)
    connect(this, SIGNAL(updatedHealthPersonaggio(int)), smp, SLOT(setHealth(int)));

    //manda a match il cambiamento di mana (pers)
    connect(this, SIGNAL(updatedManaPersonaggio(int)), smp, SLOT(setMana(int)));
}

void Controller::creaPersonaggio(int i){
    Taverna taverna;
    XmlItem base;
    std::vector<XmlItem> assoldabili;

    if(pMod==0){
        assoldabili= taverna.trovaTuttiLivello(1);
        base=assoldabili[static_cast<unsigned int>(i)];
        pMod=new Partita(base.convertiInPersonaggio());
        getMostro(static_cast<int>(pMod->getRound())-1);
        creaMatch();
    }else{
        assoldabili= taverna.trovaTuttiLivello(static_cast<int>(pMod->getRound()));
        base=assoldabili[static_cast<unsigned int>(i)];
        if(base.getPrezzo() > pMod->getMonete()){
            QMessageBox* error = new QMessageBox(mw);
            error->setObjectName("error");
            error->setInformativeText("Non hai monete a sufficienza per comprare questo personaggio.");
            error->setDetailedText("Hai bisogno di " + QString::number((base.getPrezzo() - pMod->getMonete())) + " monete in piu per acquistarlo.");
            error->show();
        } else{
            pMod->aggiungiPersonaggio(base.convertiInPersonaggio());
            getMostro(static_cast<int>(pMod->getRound())-1);
            pMod->setMonete(base.getPrezzo());
            creaMatch();
        }
    }
}

void Controller::getMostro(int i){
    Dungeon mostro;
    pMod->cambiaMostro(mostro.challengeMonster(i));
}

void Controller::getAction(QString a) try{
    if(pMod->getHealthPersonaggio() == 0)
        throw 4;

    if(a == "baseAttack"){
        int baPersonaggio = pMod->getBAPersonaggio()*(-1);
        pMod->attaccaMostro(baPersonaggio);
        emit updatedHPMostro(pMod->getHealthMostro());
    }
    else if (a == "abilita1"){
        int abilita1Personaggio = pMod->getAbilita1();
        eseguiAbilita(abilita1Personaggio, false);
    }
    else if (a == "abilita2"){
        int abilita2Personaggio = pMod->getAbilita2();
        eseguiAbilita(abilita2Personaggio, false);
    } else if (a == "cambiaPersonaggio"){
        throw 7; //7=cambia personaggio: non voglio che prosegua il round
    } else {
        int abilita3Personaggio = pMod->getAbilita3();
        if(pMod->getTurnoA3()!=0)
            throw 2;
        else{
            emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
            eseguiAbilita(abilita3Personaggio, true);
            pMod->setTurniA3(3);
        }
    }
    monsterAttack();
    endRoundActions();
}catch(int x){
    QMessageBox* error = new QMessageBox(mw);
    switch(x){
        case 1: {endRoundActions();} break; //per quando muore il mostro
        case 2: {//per quando non sono passati 3 turni per l'abilità 3
            error->setObjectName("error");
            error->setInformativeText("Abilità non utilizzabile.");
            error->setDetailedText("Puoi utilizzare questa abilità tra " + QString::number(pMod->getTurnoA3()) + " turni.");
            error->show();
        }break;
        case 4: { //per quando il personaggio morto
            error->setObjectName("error");
            error->setInformativeText("Il tuo personaggio e' morto.");
            error->show();

            int ret = error->exec();

            switch (ret) {
              case QMessageBox::Ok:
                    setVistaCambiaPersonaggio();
                    break;
            }
        }
            break;
        case 5: { //per quando non c'è abbastanza mana
            error->setObjectName("error");
            error->setInformativeText("Non hai abbastanza mana.");
            error->show();
        }
            break;
        case 7: setVistaCambiaPersonaggio(); break; //per il cambio personaggio: così non prosegue il turno
    }
}

void Controller::setVistaCambiaPersonaggio(){
    ChangeCharacter* cc = new ChangeCharacter(pMod->getSquadra(), mw->centralWidget());
    mw->setCentralWidget(cc);
    connect(mw->centralWidget(), SIGNAL(assoldaBtn(QString)), this, SLOT(cambiaPersonaggioController(QString)));
}

void Controller::monsterAttack(){
    if(pMod->getHealthMostro() == 0)
        throw 1;
    int r = rand()%4;
    int attacco = 0;
    switch(r){
        case 0: attacco = pMod->getBAMostro()*(-1); break;
        case 1: attacco = pMod->getAbilitaM1(); break;
        case 2: attacco = pMod->getAbilitaM2(); break;
        case 3: attacco = pMod->getAbilitaM3(); break;
    }
    pMod->attaccaPersonaggio(attacco);
    emit updatedHealthPersonaggio(pMod->getHealthPersonaggio());
}

//controlla se il mostro è morto
void Controller::endRoundActions(){
    bool fineRound = pMod->fineRound();

    if(fineRound && pMod->squadraSconfitta() == false && pMod->getRound()!=5){
        QMessageBox* winner = new QMessageBox(mw);
        winner->setObjectName("winner");
        winner->setInformativeText("HAI VINTO IL ROUND");
        winner->setDetailedText("I tuoi personaggi hanno guadagnato: \n" +
                                QString::number(pMod->getMoneteMostro()) + " monete \n" +
                                QString::number(pMod->getExpMostro()) + " esperienza.");
        winner->show();
        int ret = winner->exec();
        pMod->gestioneTurniAbilita3();
        switch (ret) {
          case QMessageBox::Ok:
                //apertura vista negozio
                pMod->setRound();
                creaNuovoNegozio();

                //delete del mostro
                pMod->deleteMostro();
                break;
        }
        //scelta del nuovo personaggio, viene creato il nuovo mostro
    }else if(fineRound && pMod->squadraSconfitta() == true){
        QMessageBox* loser = new QMessageBox(mw);
        loser->setObjectName("loser");
        loser->setInformativeText("HAI PERSO");
        loser->setDetailedText("Il mostro di livello " + QString::number(pMod->getLivelloMostro()) + " ti ha sconfitto.");
        loser->show();
        int ret = loser->exec();

        switch (ret) {
          case QMessageBox::Ok:
                //invio dei dati al file xml
                sMod = new StoricoModello();

                XmlItem p;
                StoricoModello::StoricoModelloItem* partita = new StoricoModello::StoricoModelloItem(QDateTime::currentDateTime().toString(), false, static_cast<int>(pMod->getRound()), pMod->getMonete());

                for(auto it=pMod->getSquadra().begin(); it!=pMod->getSquadra().end(); ++it){
                    p = XmlItem(QString::fromStdString(it->getNome()), QString::fromStdString(it->getTipoPersonaggio()), static_cast<int>(it->getLevel()), static_cast<int>(it->getPrezzo()));
                    partita->addItemToSquadra(p);
                }

                sMod->addPartita(*partita);
                sMod->saveStoricoModello();

                remakeMain();

                break;
            }
        }else if(fineRound && pMod->squadraSconfitta() == false && pMod->getRound()==5){
            QMessageBox* winner = new QMessageBox(mw);
            winner->setObjectName("winner");
            winner->setInformativeText("HAI VINTO LA PARTITA");
            winner->setDetailedText("Finirai negli annali (guarda lo storico) \n");
            winner->show();
            int ret = winner->exec();

            switch (ret) {
              case QMessageBox::Ok:
                sMod = new StoricoModello();

                XmlItem p;
                StoricoModello::StoricoModelloItem* partita = new StoricoModello::StoricoModelloItem(QDateTime::currentDateTime().toString(), true, static_cast<int>(pMod->getRound()), pMod->getMonete());

                for(auto it=pMod->getSquadra().begin(); it!=pMod->getSquadra().end(); ++it){
                    p = XmlItem(QString::fromStdString(it->getNome()), QString::fromStdString(it->getTipoPersonaggio()), static_cast<int>(it->getLevel()), static_cast<int>(it->getPrezzo()));
                    partita->addItemToSquadra(p);
                }

                sMod->addPartita(*partita);
                sMod->saveStoricoModello();

                //apertura first window
                remakeMain();

                break;
            }
        }
    else{ //fineRound == false
        //controllo sui turni (per le abilità)
        pMod->gestioneTurniAbilita3();
        emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
    }

}

void Controller::creaNuovoNegozio(){
    Taverna taverna;
    std::vector<XmlItem> assoldabili= taverna.trovaTuttiLivello(static_cast<int>(pMod->getRound()));
    Negozio_widget* newNegozio = new Negozio_widget(assoldabili, pMod->getMonete(), false, mw);
    mw->setCentralWidget(newNegozio);

    connect(newNegozio, SIGNAL(personaggioAcquistato(int)), this, SLOT(creaPersonaggio(int)));
    connect(newNegozio, SIGNAL(newMatch()), this, SLOT(createNewMatch()));
}


void Controller::createNewMatch(){
    getMostro(static_cast<int>(pMod->getRound())-1);
    creaMatch();
}

void Controller::cambiaPersonaggioController(QString s){
    int id = s.toInt();
    int cont = 0;
    Contenitore::Iteratore i;
    for(i=pMod->getSquadra().begin(); i!=pMod->getSquadra().end() && id != cont; ++i){
        cont++;
    }
    pMod->cambiaPersonaggio(i->getNome());
    creaMatch();
}
