#ifndef ARCIERE_H
#define ARCIERE_H

#include "Interfacce/dpsInterface.h"

class Arciere: public DpsInterface{
protected:
    bool increaseLevel(unsigned int newExpPoint);

public:
    /***Il costruttore richiama in automatico il costruttore standard di DpsInterface, che inizializza
    ProbCritico sempre a 20, valutare se togliere il parametro in dps o renderlo variabile***/
    Arciere(QString nome, unsigned int ex): Personaggio (50, 15, 1, 15, "Arciere", nome, 1), DpsInterface(10){
        increaseLevel(ex);
    }
    virtual ~Arciere();
    unsigned int frecciaAppuntita();
    unsigned int frecciaInfuocata();
    unsigned int frecciaPesante();
};

#endif // ARCIERE_H
