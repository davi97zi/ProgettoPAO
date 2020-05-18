#ifndef PARTITA_H
#define PARTITA_H

#include "contenitore.h"
#include "mostro.h"
/*
class Partita{
private:
    Contenitore squadra;
    Contenitore::Iteratore personaggioInUso;
    //mostro preso da xml con una funzione
    Mostro *m;
    unsigned int oro;
    unsigned int battaglia;
    //turno?

    //(1)
    void incrementaLvl(unsigned int exp){
        for(Contenitore::Iteratore it= squadra.begin(); it!=squadra.end(); ++it){
            it->increaseLevel(exp);
        }
    }

    //(2)
    void ottieniBottino(unsigned int bottino){
        oro+=bottino;
    }

    //funzione chiamata DA compraPersonaggio
    void pagaAvventuriero(unsigned int paga){
        oro-=paga;
    }

    void seppellisci(){
        for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
            if(it->getDeathState()){
                it=squadra.deleteNodo(it);
                --it;
                //salva i dati per lo storico return QDomElement???
            }
        }
    }
public:
    Partita(Personaggio* p): squadra(), personaggioInUso(), m(new Mostro()), oro(0), battaglia(1){
        squadra.addNodo(p);
        personaggioInUso=squadra.begin();
    }


    //parametro = attacco del giocatore ricevuto dal controller
    void attaccaMostro(int i){
        m->receiveDamage(i);
    }

    void guarisciTutti(int i){
        for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
            it->receiveHealing(i);
        }
    }

    void resuscita(int i){
        for(Contenitore::Iteratore it=squadra.begin(); it!=squadra.end(); ++it){
            it->receiveHealing(i, true);
        }
    }

    void attaccaPersonaggio(int i){
        personaggioInUso->receiveDamage(i);
    }

    void cambiaPersonaggio(QString nome){
        if(trovaPersonaggio(nome)->getDeathState()){
            personaggioInUso= trovaPersonaggio(nome); // contenitore::iteratore & trovaPersonaggio(QString) const in CONTENITORE!
        }
        else{
            //errore eccezione, personaggioInUso non cambia
        }

    }

    void cambiaMostro(){
        //funzione trova il mostro successivo dal file xml in base a battaglia
    }



/*
f1: dice se ha vinto la PARTITA
f2: dice se ha vinto la BATTAGLIA
f3: dice se la battaglia è in corso o è finita?
* /
    //f3 true= tutti morti, false= battaglia in corso
    bool battagliaTerminata(){
        bool squadraSconfitta=true;
        for(Contenitore::Iteratore i= squadra.begin(); i!=squadra.end() && !squadraSconfitta; ++i){
            if(!i->getDeathState()){
                squadraSconfitta=false;
            }
        }
        return squadraSconfitta;
    }


    //f2
    bool fineBattaglia(){
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

    bool finePartita(){
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

}
*/
#endif // PARTITA_H
