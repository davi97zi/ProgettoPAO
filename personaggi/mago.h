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
    /*Mago(string nome, unsigned int ex): MagicInterface(40,20,1,15,"Mago",nome,1,100){ //ultimo parametro = maxMana iniziale
        while(ex >= 100)
            increaseLevel(ex);
    }*/

    Mago(string nome, unsigned int ex): Personaggio(80,20,1,15,"Mago",nome,0), MagicInterface(100){
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

//PER TEST
std::ostream& operator<<(std::ostream&, const Mago&);

#endif // MAGO_H
