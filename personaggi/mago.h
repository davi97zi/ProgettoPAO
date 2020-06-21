#ifndef MAGO_H
#define MAGO_H

#include "../interfacce/magic_interface.h"

class Mago: public MagicInterface{
private:
    unsigned int expelliarmus();
    unsigned int expectoPatronum();
    unsigned int avadaKedavra();
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Mago(string nome, unsigned int ex): Personaggio(85,20,1,9,"Mago",nome,0), MagicInterface(100){
        increaseLevel(ex);
        setCostoA1(50);
        setCostoA2(80);
        setCostoA3(100);
    }
    virtual ~Mago() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // MAGO_H
