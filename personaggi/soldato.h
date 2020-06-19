#ifndef SOLDATO_H
#define SOLDATO_H

#include "../interfacce/dps_interface.h"
#include <iostream>

class Soldato: public DpsInterface{
private:
    unsigned int pugnoFurtivo() const;
    unsigned int fendente() const;
    unsigned int coltellata() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    /***Il costruttore richiama in automatico il costruttore standard di DpsInterface, che inizializza
    ProbCritico sempre a 20, valutare se togliere il parametro in dps***/
    Soldato(string nome, unsigned int ex): Personaggio(65, 20, 1, 25, "Soldato", nome, 0), DpsInterface(10){
        increaseLevel(ex);
    }
    virtual ~Soldato() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

//PER TEST
std::ostream& operator<<(std::ostream&, const Soldato&);

#endif // SOLDATO_H
