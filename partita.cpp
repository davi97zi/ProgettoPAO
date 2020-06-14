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

//attacco del mostro
void Partita::attaccaPersonaggio(int i){
    personaggioInUso->receiveDamage(i);
}


void Partita::cambiaMostro(Mostro* m2){
    m = m2;
}

//tutta la squadra è morta -> ritorna true se tutta la squadra è stata sconfitta (il mostro ha vinto), else altrimenti (c'è qualche personaggio ancora vivo)
bool Partita::squadraSconfitta(){
    bool squadraSconfitta=false;
    for(Contenitore::Iteratore i= squadra.begin(); i!=squadra.end() && squadraSconfitta; ++i){
        qDebug() << "death state personaggio: " << i->getDeathState();
        if(!i->getDeathState()){
            squadraSconfitta=false;
        }else
            squadraSconfitta=true;
    }
    return squadraSconfitta;
}

/*
 * ROUND: FINE DELLA BATTAGLIA TRA MOSTRO E PERSONAGGIO (MOSTRO MUORE / PERSONAGGIO MUORE)
 * TURNO: SCAMBIO DI ATTACCHI (2) TRA MOSTRO (1) E PERSONAGGIO (1)
*/
//dice chi ha vinto
bool Partita::fineRound(){
    bool termine= squadraSconfitta();
    if(termine){
        return true;
    } else{
        //se il mostro è morto
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

//fine dei livelli
bool Partita::finePartita(){
    if(battaglia==5 && fineRound()){
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


void Partita::deleteMostro(){
    delete m;
    m=0;
}


short Partita::getTurnoA3() const
{
    return personaggioInUso->getTurniAbilita3();
}

void Partita::setTurniA3(int a)
{
    personaggioInUso->setTurniAbilita3(a);
}
/*
void Partita::resetArmor()
{
    qDebug()<<"entra da resetArmor";
    dynamic_cast<DefenceInterface*>(&(*personaggioInUso))->setDefaultArmor();
    qDebug()<<"esce da resetArmor";
}
*/

int Partita::getHealthMostro() const{
    return m->getHealth();
}

int Partita::getBAMostro() const{
    return m->getBaseAttack();
}

int Partita::getArmorMostro() const{
    return m->getArmor();
}

int Partita::getLivelloMostro() const{
    return m->getLevel();
}

int Partita::getExpMostro() const{
    return m->getExpPoint();
}

QString Partita::getNomeMostro() const{
    return m->getNome();
}

int Partita::getHealthPersonaggio() const{
    return personaggioInUso->getHealth();
}

int Partita::getBAPersonaggio() const{
    return personaggioInUso->getBaseAttack();
}

int Partita::getArmorPersonaggio() const{
    return personaggioInUso->getArmor();
}

int Partita::getLivelloPersonaggio() const{
    return personaggioInUso->getLevel();
}

int Partita::getManaPersonaggio() const{
    Personaggio* p2 = &(*personaggioInUso);
    MagicInterface* p = dynamic_cast<MagicInterface*>(p2);
    if(!p)
        return 0;
    else
        return p->getMana();
}

QString Partita::getNomePersonaggio() const{
    return personaggioInUso->getNome();
}

int Partita::getRound() const{
    return battaglia;
}

int Partita::getMonete() const{
    return oro;
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

int Partita::getAbilitaM1() const{
    return m->abilita1();
}

int Partita::getAbilitaM2() const{
    return m->abilita2();
}

int Partita::getAbilitaM3() const{
    return m->abilita3();
}

void Partita::gestioneTurniAbilita3(){
    for(Contenitore::Iteratore i= squadra.begin(); i!=squadra.end(); ++i){
        if(i->getTurniAbilita3() != 0)
            i->setTurniAbilita3(-1);
        DefenceInterface* df = dynamic_cast<DefenceInterface*>(&*i);
        if(df && i->getTurniAbilita3() == 0)
            df->setDefaultArmor();
    }
}
