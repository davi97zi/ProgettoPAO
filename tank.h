#ifndef TANK_H
#define TANK_H

#include "Interfacce/defenceInterface.h"

class Tank: public DefenceInterface{
private:
    //if tank is up, he gets all the damage (buffArmor == true)
    bool scudo();
    unsigned int schiacciasassi() const;
    unsigned int jackhammer() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Tank(QString nome, unsigned int ex): Personaggio(80,6,1,25,"Tank",nome,1), DefenceInterface(35) {   //MaxArmor come MaxMana?
        increaseLevel(ex);
    }
    virtual ~Tank() {}



    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // TANK_H
