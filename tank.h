#ifndef TANK_H
#define TANK_H

#include "Interfacce/defenceInterface.h"

class Tank: public DefenceInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Tank(QString nome, unsigned int ex): Personaggio(80,6,1,25,"Tank",nome,1), DefenceInterface(35) {   //MaxArmor come MaxMana?
        increaseLevel(ex);
    }
    virtual ~Tank() {}

    //if tank is up, he gets all the damage (buffArmor == true)
    bool scudo();
    unsigned int schiacciasassi();
    unsigned int jackhammer();
};

#endif // TANK_H
