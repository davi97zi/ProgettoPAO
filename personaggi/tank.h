#ifndef TANK_H
#define TANK_H

#include "../interfacce/defence_interface.h"

class Tank: public DefenceInterface{
private:
    unsigned int schiacciasassi() const;
    unsigned int jackhammer() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Tank(string nome, unsigned int ex): Personaggio(110,8,1,25,"Tank",nome,0), DefenceInterface(25) {
        increaseLevel(ex);
    }
    virtual ~Tank() {}

    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // TANK_H
