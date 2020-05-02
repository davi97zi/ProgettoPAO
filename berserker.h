#ifndef BERSERKER_H
#define BERSERKER_H

#include "Interfacce/dpsInterface.h"
#include "Interfacce/defenceInterface.h"

class Berserker: public DpsInterface, public DefenceInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);
public:
    /***Il costruttore richiama in automatico il costruttore standard di DpsInterface, che inizializza
    ProbCritico sempre a 20, valutare se togliere il parametro in dps***/
    //max serve per inizializzare maxarmor di defenceinterface
    Berserker(QString nome, unsigned int ex)
      : Personaggio (120, 70, 1, 50, "Berserker", nome, 5), DpsInterface(10), DefenceInterface(50){
            increaseLevel(ex);
    }
    virtual ~Berserker() {}
    unsigned int attaccoFurioso();
    unsigned int asciaDiFuoco();
    unsigned int furiaAssassina();
};

#endif // BERSERKER_H
