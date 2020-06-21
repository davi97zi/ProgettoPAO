#ifndef HEAL_INTERFACE_H
#define HEAL_INTERFACE_H

#include "personaggio.h"

class HealInterface: virtual public Personaggio{
private:
    unsigned int blessing; //parte da lvl-1, aumenta per ogni turno di attacco SEMPLICE durante una BATTAGLIA

protected:
    void prayForBlessing();//aumenta blessing
    void resetBlessing();
    unsigned int askForBlessing();//chiamato per usare il blessing accumulato e fare il reset del blessing
    void increaseBlessing();//chiamato da increaseLevel

public:
    HealInterface(unsigned int b=0): blessing(b){}
    unsigned int getBlessing()const;
    virtual unsigned int pray(bool use);// può essere usato x accumulare blessing

};


#endif // HEAL_INTERFACE_H
