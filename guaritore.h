#ifndef GUARITORE_H
#define GUARITORE_H

#include "Interfacce/healInterface.h"

class Guaritore: public HealInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoints);
public:
    //NB consiglio di aggiungere PREZZO QUI COME ESPLICITO!!!
    Guaritore(QString nome, unsigned int ex): Personaggio(20, 10, 1, 5, "guaritore", nome, 2), HealInterface(){
        increaseLevel(ex);
    }

    virtual unsigned int useBlessing();//ridef da healIterf

    //add or get juice
    virtual unsigned int pray(bool use);

    unsigned int healingWord();//usato per guarire se stessi e gli altri

    unsigned int smite(); //usato per attacco benedetto

    unsigned int divineIntervention();//USATO PER RIPORTARE IN VITA UN PERSONAGGIO CADUTO IN BATTAGLIA

};

#endif // GUARITORE_H
