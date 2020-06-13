#include "partita.h"
#include "xml/dungeon.h"
#include "Interfacce/magicInterface.h"

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
        it->receiveHealing(static_cast<unsigned int>(i));
    }
}

void Partita::resuscita(int i){
    for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
        it->receiveHealing(static_cast<unsigned int>(i), true);
    }
}

void Partita::aggiungiPersonaggio(Personaggio *p){
    squadra.addNodo(p);
    //stampaSquadra();
}

void Partita::attaccaPersonaggio(int i){
    personaggioInUso->receiveDamage(i);
}


void Partita::cambiaMostro(Mostro* m2){
    m = m2;
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

short Partita::getTurnoA3() const
{
    return personaggioInUso->getTurniAbilita3();
}

void Partita::setTurniA3(int a)
{
    personaggioInUso->setTurniAbilita3(a);
}

void Partita::resetArmor()
{
    qDebug()<<"entra da resetArmor";
    dynamic_cast<DefenceInterface*>(&(*personaggioInUso))->setDefaultArmor();
    qDebug()<<"esce da resetArmor";
}


int Partita::getHealthMostro() const{
    return m->getHealth();
}

int Partita::getBAMostro() const{
    return static_cast<int>(m->getBaseAttack());
}

int Partita::getArmorMostro() const{
    return static_cast<int>(m->getArmor());
}

int Partita::getLivelloMostro() const{
    return static_cast<int>(m->getLevel());
}

int Partita::getExpMostro() const{
    return static_cast<int>(m->getExpPoint());
}

QString Partita::getNomeMostro() const{
    return m->getNome();
}

int Partita::getHealthPersonaggio() const{
    return personaggioInUso->getHealth();
}

int Partita::getBAPersonaggio() const{
    return static_cast<int>(personaggioInUso->getBaseAttack());
}

int Partita::getArmorPersonaggio() const{
    return static_cast<int>(personaggioInUso->getArmor());
}

int Partita::getLivelloPersonaggio() const{
    return static_cast<int>(personaggioInUso->getLevel());
}

int Partita::getManaPersonaggio() const{
    Personaggio* p2 = &(*personaggioInUso);
    MagicInterface* p = dynamic_cast<MagicInterface*>(p2);
    if(!p)
        return 0;
    else
        return static_cast<int>(p->getMana());
}

QString Partita::getNomePersonaggio() const{
    return personaggioInUso->getNome();
}

int Partita::getRound() const{
    return static_cast<int>(battaglia);
}

int Partita::getMonete() const{
    return static_cast<int>(oro);
}

int Partita::getAbilita1() const{
    return personaggioInUso->abilita1();
}

int Partita::getAbilita2() const{
    return personaggioInUso->abilita2();
}

int Partita::getAbilita3() const{
    return personaggioInUso->abilita3();
}
