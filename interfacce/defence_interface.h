#ifndef DEFENCE_INTERFACE_H
#define DEFENCE_INTERFACE_H

#include "personaggio.h"

class DefenceInterface: virtual public Personaggio{
private:
    unsigned short int turni;
    unsigned int maxArmor;

protected:
    virtual unsigned int reducedDamageWithArmor(unsigned int damage) const;
    //increaseArmor utilizzato in increaseLevel
    virtual void increaseArmor(unsigned int valAdd);

public:
    DefenceInterface(unsigned int m): turni(0), maxArmor(m){}//NB turni dovrebbe essere zero?
    virtual void buffArmor(); //incrementa l'armatura
    void setDefaultArmor();

};

#endif // DEFENCE_INTERFACE_H

