#include "controller.h"

/*StoricoModello::StoricoModelloItem Controller::getStoricoRow(int i){
    return s->getPartita(i);
}*/

void Controller::eseguiAbilita(int abilita, bool terza){
    if(abilita<0){ //è un attacco
        qDebug() << "è un attacco, danno: " << abilita;
        pMod->attaccaMostro(abilita);
        emit updatedHPMostro(pMod->getHealthMostro());
        emit updatedManaPersonaggio(pMod->getManaPersonaggio());
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
    smp = nullptr;
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
        qDebug() << "gioca";

        Taverna taverna;
        //creo taverna e trovo personaggi di liv 1
        std::vector<XmlItem> assoldabili= taverna.trovaTuttiLivello(1);

        //creo il negozio x scegliere primo personaggio (inizio= true)
        Negozio_widget* negozio= new Negozio_widget(assoldabili, 0, true);
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
    if(pMod){
        delete pMod;
        pMod=0;
    }
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
    StatisticheMatchMostro* smm = new StatisticheMatchMostro(pMod->getHealthMostro(), pMod->getBAMostro(), pMod->getArmorMostro(), QString::fromStdString(pMod->getNomeMostro()), pMod->getLivelloMostro(), pMod->getExpMostro());
    smp = new StatisticheMatchPersonaggio(pMod->getHealthPersonaggio(), pMod->getBAPersonaggio(), pMod->getArmorPersonaggio(), QString::fromStdString(pMod->getNomePersonaggio()), pMod->getLivelloPersonaggio(), pMod->getManaPersonaggio());
    Match* m = new Match(smm, smp, pMod->getRound(), pMod->getMonete());
    qDebug() << "Controller::creaMatch() -> monete " << pMod->getMonete();
    qDebug() << "Health mostro: " << pMod->getHealthMostro();
    mw->setCentralWidget(m);
    qDebug() << "Controller::creaMatch entra";
    //prende bottone cliccato sezione abilita personaggio
    //avendo smp si può usare direttamente eseguiAbilità di statisticheMatchPersonaggio
    connect(mw->centralWidget(), SIGNAL(eseguiAbilitaP(QString)), this, SLOT(getAction(QString)));

    connect(smp, SIGNAL(cambiaPersonaggioBtn(QString)), this, SLOT(getAction(QString)));

//HO SPOSTATO QUESTA CONNECT IN setVistaCambiaPersonaggio(), ALTRIMENTI SERVE UN PUNTATORE A cc IN CONTROLLER
    //connect(mw->centralWidget(), SIGNAL(assoldaBtn(QString)), this, SLOT(cambiaPersonaggioController(QString)));

    //manda a match il danno al mostro
    connect(this, SIGNAL(updatedHPMostro(int)), smm, SLOT(setHealth(int)));

    //manda a match il cambiamento di armor (pers)
    connect(this, SIGNAL(updatedArmPersonaggio(int)), smp, SLOT(setArmor(int)));

    //manda a match il cambiamento di vita (pers)
    connect(this, SIGNAL(updatedHealthPersonaggio(int)), smp, SLOT(setHealth(int)));

    //manda a match il cambiamento di mana (pers)
    connect(this, SIGNAL(updatedManaPersonaggio(int)), smp, SLOT(setMana(int)));

    qDebug() << "Controller::creaMatch esce";
}

void Controller::creaPersonaggio(int i){
    qDebug() << "3)voglio inserire " << i << " nel mio party";
    //Queste 2 righe potrebbero dover andare in partita
    Taverna taverna;
    XmlItem base;
    std::vector<XmlItem> assoldabili;

    if(pMod==0){
        assoldabili= taverna.trovaTuttiLivello(1);
        base=assoldabili[i];
        pMod=new Partita(base.convertiInPersonaggio());
        getMostro(pMod->getRound()-1);
        creaMatch();
    }else{
        assoldabili= taverna.trovaTuttiLivello(pMod->getRound());
        base=assoldabili[i];
        if(base.getPrezzo() > pMod->getMonete()){
            //DA INSERIRE IN UN CATCH
            QMessageBox* error = new QMessageBox(mw);
            error->setObjectName("error");
            error->setInformativeText("Non hai monete a sufficienza per comprare questo personaggio.");
            error->setDetailedText("Hai bisogno di " + QString::number((base.getPrezzo() - pMod->getMonete())) + " monete in piu per acquistarlo.");
            error->show();
        } else{
            pMod->aggiungiPersonaggio(base.convertiInPersonaggio());
            getMostro(pMod->getRound()-1);
            pMod->setMonete(base.getPrezzo());
            creaMatch();
        }
    }
}

void Controller::getMostro(int i){
    Dungeon mostro;
    pMod->cambiaMostro(mostro.challengeMonster(i));
}

//personaggio action (da match window)
void Controller::getAction(QString a) try{
    qDebug()<<"entra in getAction";

    if(pMod->getHealthPersonaggio() == 0)
        throw 4;

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
    } else if (a == "cambiaPersonaggio"){
        qDebug() << "Controller::getAction: " << a;
        throw 7; //7=cambia personaggio: non voglio che prosegua il round
    } else {
        qDebug() << a;
        int abilita3Personaggio = pMod->getAbilita3();
        if(pMod->getTurnoA3()!=0)
            throw 2;
        else{
            emit updatedArmPersonaggio(pMod->getArmorPersonaggio());
            eseguiAbilita(abilita3Personaggio, true);
            pMod->setTurniA3(3);
        }
    }
    qDebug()<<QString::fromStdString(pMod->getNomePersonaggio())<<"turni A3 mancanti: "<<pMod->getTurnoA3();
    monsterAttack();
    endRoundActions();
}catch(int x){
    QMessageBox* error = new QMessageBox(mw);
    switch(x){ //MESSAGGI CHE SPIEGANO L'INTERRUZIONE!! QMessageBox??
        case 1: {qDebug()<<"throw 1: il mostro e' morto e non puo attaccare"; endRoundActions(); } break;
        case 2: {
            qDebug()<<"throw 2: abilita' non utilizzabile";
            error->setObjectName("error");
            error->setInformativeText("Abilità non utilizzabile.");
            error->setDetailedText("Puoi utilizzare questa abilità tra " + QString::number(pMod->getTurnoA3()) + " turni.");
            error->show();
        }break; //per quando non sono passati 3 turni per l'abilità 3
        case 3: qDebug()<<"throw 3"; break; //per il guaritore (abilità 3)
        //case 4: personaggio morto
        case 4: {
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
        case 5: {
            qDebug()<<"throw 5: non abbastanza mana";
            error->setObjectName("error");
            error->setInformativeText("Non hai abbastanza mana.");
            error->show();
        }
            break; //per quando non c'è abbastanza mana
        case 7: qDebug()<<"throw 7"; setVistaCambiaPersonaggio(); break; //per il cambio personaggio: così non prosegue il turno
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
    qDebug() << "random number: " << r << " Attacco del mostro: " << attacco;
    pMod->attaccaPersonaggio(attacco);
    emit updatedHealthPersonaggio(pMod->getHealthPersonaggio());
}

//controlla se il mostro è morto
void Controller::endRoundActions(){
    bool fineRound = pMod->fineRound();
    qDebug() << "fineRound = " << fineRound;
    qDebug() << "squadraSconfitta = " << pMod->squadraSconfitta();

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
                qDebug() << pMod->getMonete();
                //pMod->setMonete(pMod->getMoneteMostro());
                qDebug() << pMod->getMonete();
                creaNuovoNegozio();

                //delete del mostro
                pMod->deleteMostro();
                break;

        }
        //scelta del nuovo personaggio viene creato il nuovo mostro
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
                StoricoModello::StoricoModelloItem* partita = new StoricoModello::StoricoModelloItem(QDateTime::currentDateTime().toString(), false, pMod->getRound(), pMod->getMonete());

                for(auto it=pMod->getSquadra().begin(); it!=pMod->getSquadra().end(); ++it){
                    qDebug() << "Controller::endRoundActions(): passaggio dei parametri al nuovo xmlitem \n" << QString::fromStdString(it->getNome()) <<" " << QString::fromStdString(it->getTipoPersonaggio()) <<" " << it->getLevel() <<" " << it->getPrezzo();
                    p = XmlItem(QString::fromStdString(it->getNome()), QString::fromStdString(it->getTipoPersonaggio()), it->getLevel(), it->getPrezzo());
                    qDebug() << "p.stampaItem() --------------------";
                    p.stampaItem(); //ok
                    qDebug() << "-------------------------";
                    partita->addItemToSquadra(p);
                    qDebug() << "partita->stampaStoricoModelloItem() -------------------- ";
                    partita->stampaStoricoModelloItem();
                }

                sMod->addPartita(*partita);
                //sMod->stampaStoricoModello();
                sMod->saveStoricoModello();

                //apertura first window
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
                StoricoModello::StoricoModelloItem* partita = new StoricoModello::StoricoModelloItem(QDateTime::currentDateTime().toString(), true, pMod->getRound(), pMod->getMonete());

                for(auto it=pMod->getSquadra().begin(); it!=pMod->getSquadra().end(); ++it){
                    qDebug() << "Controller::endRoundActions(): passaggio dei parametri al nuovo xmlitem \n" << QString::fromStdString(it->getNome()) <<" " << QString::fromStdString(it->getTipoPersonaggio()) <<" " << it->getLevel() <<" " << it->getPrezzo();
                    p = XmlItem(QString::fromStdString(it->getNome()), QString::fromStdString(it->getTipoPersonaggio()), it->getLevel(), it->getPrezzo());
                    qDebug() << "p.stampaItem() --------------------";
                    p.stampaItem(); //ok
                    qDebug() << "-------------------------";
                    partita->addItemToSquadra(p);
                    qDebug() << "partita->stampaStoricoModelloItem() -------------------- ";
                    partita->stampaStoricoModelloItem();
                }

                sMod->addPartita(*partita);
                //sMod->stampaStoricoModello();
                sMod->saveStoricoModello();

                //apertura first window
                remakeMain();

                break;
            }
        }
        //passaggio dei dati allo storico dei dati della partita persa
        //rimandare alla schermata iniziale "firstWindow"
    else{ //fineRound == false
        //controllo sui turni (per le abilità)
        pMod->gestioneTurniAbilita3();
    }
}

void Controller::creaNuovoNegozio(){
    Taverna taverna;
    std::vector<XmlItem> assoldabili= taverna.trovaTuttiLivello(pMod->getRound());
    qDebug() << "Controller::creaNuovoNegozio() -> monete" << pMod->getMonete();
    Negozio_widget* newNegozio = new Negozio_widget(assoldabili, pMod->getMonete(), false, mw);
    mw->setCentralWidget(newNegozio);

    connect(newNegozio, SIGNAL(personaggioAcquistato(int)), this, SLOT(creaPersonaggio(int)));
    connect(newNegozio, SIGNAL(newMatch()), this, SLOT(createNewMatch()));
}


void Controller::createNewMatch(){
    getMostro(pMod->getRound()-1);
    creaMatch();
}

void Controller::cambiaPersonaggioController(QString s){
    qDebug()<<"entra in Controller::cambiaPersonaggioController";
    int id = s.toInt();
    int cont = 0;
    Contenitore::Iteratore i;
    for(i=pMod->getSquadra().begin(); i!=pMod->getSquadra().end() && id != cont; ++i){
        cont++;
    }
    pMod->cambiaPersonaggio(i->getNome());
    qDebug()<<QString::fromStdString(pMod->getNomePersonaggio())<<"turni A3 mancanti: "<<pMod->getTurnoA3();
    creaMatch();
}
