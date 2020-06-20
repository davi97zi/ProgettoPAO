#ifndef ARTIFICIERE_H
#define ARTIFICIERE_H

#include "../interfacce/dps_interface.h"
#include "../interfacce/magic_interface.h"

class Artificiere : public DpsInterface, public MagicInterface{
private:
    unsigned int bombardaMaxima();
    unsigned int rainOfSpells();
    unsigned int distruzione();
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Artificiere(string nome, unsigned int ex): Personaggio(100,20,1,10,"Artificiere",nome,0), DpsInterface(10), MagicInterface(100) {
        increaseLevel(ex);
        setCostoA1(30);
        setCostoA2(40);
        setCostoA3(70);
    }
    virtual ~Artificiere() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // ARTIFICIERE_H

