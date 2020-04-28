#ifndef HEALINTERFACE_H
#define HEALINTERFACE_H

#include "personaggio.h"

class HealInterface: virtual public Personaggio{

private:
    unsigned int blessing; //parte da lvl-1, aumenta per ogni turno di attacco SEMPLICE durante una BATTAGLIA

protected:
    void prayForBlessing();//chiamato da azione determinata da classe derivata, aumenta blessing

    void resetBlessing(); // da personaggio

    unsigned int askForBlessing();//chiamato per usare il blessing accumulato e fare il reset del blessing

    void increaseBlessing();//chiamato da increaseLevel->(!) must be VIRTUAL! al salire di livello


public:
    HealInterface(unsigned int b=0): blessing(b){}//se il livello è 1->vale zero, altrimenti passa lvl-1

    unsigned int getBlessing()const;//ritorna Blessing come VALORE IN LETTURA, usato per fare check di valore

    virtual unsigned int pray(bool use);// può essere usato x accumulare blessing tramite preghiere O per fare "un azione benedetta dalla divinità" azzerando blessing

};


#endif // HEALINTERFACE_H
