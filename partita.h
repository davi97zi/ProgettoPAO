#ifndef PARTITA_H
#define PARTITA_H

#include "contenitore.h"
#include "mostro.h"
#include <iostream>
#include <QDebug>
class Partita{
private:
    Contenitore squadra;
    Contenitore::Iteratore personaggioInUso;

    //mostro preso da xml con una funzione
    Mostro *m;
    unsigned int oro;
    unsigned int battaglia;
    //turno?

    void incrementaLvl(unsigned int);

    void ottieniBottino(unsigned int);

    //funzione chiamata DA compraPersonaggio
    void pagaAvventuriero(unsigned int);

    void seppellisci();

public:

    Partita(Personaggio* p): squadra(), personaggioInUso(), m(new Mostro()), oro(0), battaglia(1){
        squadra.addNodo(p);
        personaggioInUso=squadra.begin();
    }


    //parametro = attacco del giocatore ricevuto dal controller
    void attaccaMostro(int);

    void guarisciTutti(int);

    void resuscita(int);

    void aggiungiPersonaggio(Personaggio*);

    void attaccaPersonaggio(int);

    /*void cambiaPersonaggio(QString nome){
        if(trovaPersonaggio(nome)->getDeathState()){
            personaggioInUso= trovaPersonaggio(nome); // contenitore::iteratore & trovaPersonaggio(QString) const in CONTENITORE!
        }
        else{
            //errore eccezione, personaggioInUso non cambia
        }

    }*/

    //MANCA DEFINIZIONE
    void cambiaMostro(Mostro*);

    int getHealthMostro() const;
    int getBAMostro() const;
    int getArmorMostro() const;
    int getLivelloMostro() const;
    int getExpMostro() const;
    QString getNomeMostro() const;

    int getHealthPersonaggio() const;
    int getBAPersonaggio() const;
    int getArmorPersonaggio() const;
    int getLivelloPersonaggio() const;
    int getManaPersonaggio() const;
    QString getNomePersonaggio() const;

    int getAbilita1() const;
    int getAbilita2() const;
    int getAbilita3() const;

    int getRound() const;
    int getMonete() const;

/*
f1: dice se ha vinto la PARTITA
f2: dice se ha vinto la BATTAGLIA
f3: dice se la battaglia è in corso o è finita?
*/
    //f3 true= tutti morti, false= battaglia in corso
    bool battagliaTerminata();

    //f2
    bool fineBattaglia();

    bool finePartita();

    short int getTurnoA3() const;
    void setTurniA3(int);
    void resetArmor();

    //PER TEST: da togliere
    void stampaSquadra() const{
        qDebug()<<"stampaSQQ";
        std::cout<<squadra;
    }

};

#endif // PARTITA_H
