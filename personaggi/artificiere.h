#ifndef ARTIFICIERE_H
#define ARTIFICIERE_H

#include "../interfacce/dps_interface.h"
#include "../interfacce/magic_interface.h"

class Artificiere : public DpsInterface, public MagicInterface{
private:
    unsigned int bombardaMaxima();
    unsigned int rainOfSpells();
    unsigned int autodistruzione();
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Artificiere(string nome, unsigned int ex): Personaggio(40,20,1,15,"Artificiere",nome,0), DpsInterface(10), MagicInterface(80) {
        increaseLevel(ex);
        setCostoA1(60);
        setCostoA2(80);
        setCostoA3(130);
    }
    virtual ~Artificiere() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // ARTIFICIERE_H

