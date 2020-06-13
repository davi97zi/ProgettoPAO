#ifndef DEFENCEINTERFACE_H
#define DEFENCEINTERFACE_H

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


    //incrementa l'armatura
    virtual void buffArmor();
    void setDefaultArmor();


};

#endif // DEFENCEINTERFACE_H

