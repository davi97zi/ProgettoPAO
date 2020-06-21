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
    Berserker(string nome, unsigned int ex)
      : Personaggio (90, 22, 1, 20, "Berserker", nome, 0), DpsInterface(5), DefenceInterface(50){
            increaseLevel(ex);
    }
    virtual ~Berserker() {}


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // BERSERKER_H
