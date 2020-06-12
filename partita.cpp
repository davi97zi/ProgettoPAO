#include "partita.h"
#include "../xml/dungeon.h"
#include "../Interfacce/magicInterface.h"

void Partita::incrementaLvl(unsigned int exp)
{
    for(Contenitore::Iteratore it= squadra.begin(); it!=squadra.end(); ++it){
        it->increaseLevel(exp);
    }
}

void Partita::ottieniBottino(unsigned int bottino){
    oro+=bottino;
}

void Partita::pagaAvventuriero(unsigned int paga){
    oro-=paga;
}

void Partita::seppellisci(){
    for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
        if(it->getDeathState()){
            it=squadra.deleteNodo(it);
            --it;
            //salva i dati per lo storico return QDomElement???
        }
    }
}

void Partita::attaccaMostro(int i){
    m->receiveDamage(i);
}

void Partita::guarisciTutti(int i){
    for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
        it->receiveHealing(i);
    }
}

void Partita::resuscita(int i){
    for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
        it->receiveHealing(i, true);
    }
}

void Partita::aggiungiPersonaggio(Personaggio *p){
    squadra.addNodo(p);
    //stampaSquadra();
}

void Partita::attaccaPersonaggio(int i){
    personaggioInUso->receiveDamage(i);
}

void Partita::cambiaMostro(){
    Dungeon d;
    d.challengeMonster(battaglia);
}


bool Partita::battagliaTerminata(){
    bool squadraSconfitta=true;
    for(Contenitore::Iteratore i= squadra.begin(); i!=squadra.end() && !squadraSconfitta; ++i){
        if(!i->getDeathState()){
            squadraSconfitta=false;
        }
    }
    return squadraSconfitta;
}

bool Partita::fineBattaglia(){
    bool termine= battagliaTerminata();
    if(termine){
        return true;
    }
    else{
        if(m->getDeathState()){//true= morto, false= vivo
            //elimina personaggi morti
            seppellisci();
            //aumenta livello personaggi (1)
            incrementaLvl(m->giveUpExp());
            //ottieni oro (2)
            ottieniBottino(m->giveUpCoins());
            //vai al negozio tramite controller
            return true;
        }
        else{
            return false;
        }
    }
}

bool Partita::finePartita(){
    if(battaglia==5 && fineBattaglia()){
        return true;
        //controller richiama QDialog hai vinto: OK -> manda a main window
        //inserisci dati nello storico
    }
    else{
        return false;
        //controller richiama QDialog hai perso: OK -> manda a main window
        //inserisci dati nello storico
    }
}

int Partita::getHealthMostro(){
    return m->getHealth();
}

int Partita::getBAMostro(){
    return m->getBaseAttack();
}

int Partita::getArmorMostro(){
    return m->getArmor();
}

int Partita::getLivelloMostro(){
    return m->getLevel();
}

QString Partita::getNomeMostro(){
    return m->getNome();
}

int Partita::getHealthPersonaggio(){
    return personaggioInUso->getHealth();
}

int Partita::getBAPersonaggio(){
    return personaggioInUso->getBaseAttack();
}

int Partita::getArmorPersonaggio(){
    return personaggioInUso->getArmor();
}

int Partita::getLivelloPersonaggio(){
    return personaggioInUso->getLevel();
}

int Partita::getManaPersonaggio(){
    Personaggio* p2 = &(*personaggioInUso);
    MagicInterface* p = dynamic_cast<MagicInterface*>(p2);
    if(!p)
        return 0;
    else
        return p->getMana();
}

QString Partita::getNomePersonaggio(){
    return personaggioInUso->getNome();
}

int Partita::getTurno(){
    return battaglia;
}

int Partita::getMonete(){
    return oro;
}
