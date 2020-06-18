#ifndef BERSERKER_H
#define BERSERKER_H

#include "../interfacce/dps_interface.h"
#include "../interfacce/defence_interface.h"

class Berserker: public DpsInterface, public DefenceInterface{
private:
    unsigned int asciaDiFuoco() const;
    unsigned int furiaAssassina() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);
public:
    /***Il costruttore richiama in automatico il costruttore standard di DpsInterface, che inizializza
    ProbCritico sempre a 20, valutare se togliere il parametro in dps***/
    //max serve per inizializzare maxarmor di defenceinterface
    Berserker(QString nome, unsigned int ex)
      : Personaggio (120, 70, 1, 50, "Berserker", nome, 0), DpsInterface(10), DefenceInterface(50){
            increaseLevel(ex);
    }
    virtual ~Berserker() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // BERSERKER_H
