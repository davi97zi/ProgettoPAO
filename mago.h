#ifndef MAGO_H
#define MAGO_H

#include "Interfacce/magicInterface.h"

class Mago: public MagicInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    /*Mago(QString nome, unsigned int ex): MagicInterface(40,20,1,15,"Mago",nome,1,100){ //ultimo parametro = maxMana iniziale
        while(ex >= 100)
            increaseLevel(ex);
    }*/

    Mago(QString nome, unsigned int ex): Personaggio(40,20,1,15,"Mago",nome,1), MagicInterface(100){
        while(ex >= 100){//NB aggiunto ex-=100; per evitare ciclo infinito
            increaseLevel(ex);
            ex-=100;
        }
        setCostoA1(50);
        setCostoA2(80);
        setCostoA3(110);
    }
    virtual ~Mago() {}

    unsigned int expelliarmus();
    unsigned int expectoPatronum();
    unsigned int avadaKedavra();
};

#endif // MAGO_H
