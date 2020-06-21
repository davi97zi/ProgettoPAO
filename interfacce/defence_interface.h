#ifndef DEFENCE_INTERFACE_H
#define DEFENCE_INTERFACE_H

#include "personaggio.h"

class DefenceInterface: virtual public Personaggio{
private:
    unsigned short int turni;
    unsigned int maxArmor;

protected:
    virtual int reducedDamageWithArmor(int damage) const;
    //increaseArmor utilizzato in increaseLevel
    virtual void increaseArmor(unsigned int valAdd);

public:
    DefenceInterface(unsigned int m): turni(0), maxArmor(m){}
    virtual void buffArmor(); //incrementa l'armatura (abilita')
    void setDefaultArmor();

};

#endif // DEFENCE_INTERFACE_H

