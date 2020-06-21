#ifndef PARTITA_H
#define PARTITA_H

#include "personaggi/mostro.h"
#include "xml/dungeon.h"
#include "interfacce/magic_interface.h"
#include "contenitore.h"


class Partita{
private:
    Contenitore squadra;
    Contenitore::Iteratore personaggioInUso;
    //mostro preso da xml con una funzione
    Mostro *m;
    unsigned int oro;
    unsigned int battaglia;

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

    ~Partita(){
        delete m;
    }

    //parametro = attacco del giocatore ricevuto dal controller
    void attaccaMostro(int);
    void guarisciTutti(int);
    void resuscita(int);
    void aggiungiPersonaggio(Personaggio*);
    void attaccaPersonaggio(int);
    void deleteMostro();
    Contenitore getSquadra();

    void cambiaMostro(Mostro*);

    int getHealthMostro() const;
    int getBAMostro() const;
    int getArmorMostro() const;
    int getLivelloMostro() const;
    int getExpMostro() const;
    string getNomeMostro() const;
    int getMoneteMostro() const;

    int getHealthPersonaggio() const;
    int getBAPersonaggio() const;
    int getArmorPersonaggio() const;
    int getLivelloPersonaggio() const;
    int getManaPersonaggio() const;
    string getNomePersonaggio() const;

    int getAbilita1() const;
    int getAbilita2() const;
    int getAbilita3() const;

    int getAbilitaM1() const;
    int getAbilitaM2() const;
    int getAbilitaM3() const;

    unsigned int getRound() const;
    void setRound();
    int getMonete() const;
    void setMonete(int);

    void cambiaPersonaggio(string s);

/*
f1: dice se ha vinto la PARTITA
f2: dice se ha vinto la BATTAGLIA
f3: dice se la battaglia è in corso o è finita?
*/
    //f3 true= tutti morti, false= battaglia in corso
    bool squadraSconfitta();

    //f2
    bool fineRound();

    bool finePartita();

    int getTurnoA3() const;
    void setTurniA3(int);
    void gestioneTurniAbilita3();

};

#endif // PARTITA_H
