#ifndef SOLDATO_H
#define SOLDATO_H

#include "../interfacce/dps_interface.h"

class Soldato: public DpsInterface{
private:
    unsigned int pugnoFurtivo() const;
    unsigned int fendente() const;
    unsigned int coltellata() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Soldato(string nome, unsigned int ex): Personaggio(70, 18, 1, 18, "Soldato", nome, 0), DpsInterface(10){
        increaseLevel(ex);
    }
    virtual ~Soldato() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // SOLDATO_H
