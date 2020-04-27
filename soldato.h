#ifndef SOLDATO_H
#define SOLDATO_H

#include "Interfacce/dpsInterface.h"

class Soldato: public DpsInterface{
protected:
    bool increaseLevel(unsigned int newExpPoint);

public:
    /***Il costruttore richiama in automatico il costruttore standard di DpsInterface, che inizializza
    ProbCritico sempre a 20, valutare se togliere il parametro in dps***/
    Soldato(QString nome, unsigned int ex): Personaggio (65, 20, 1, 25, "Soldato", nome, 1){
        while(ex >= 100)
            increaseLevel(ex);
    }
    virtual ~Soldato() {}
    unsigned int pugnoFurtivo();
    unsigned int fendente();
    unsigned int coltellata();
};


#endif // SOLDATO_H
