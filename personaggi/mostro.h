#ifndef MOSTRO_H
#define MOSTRO_H

#include "../interfacce/personaggio.h"

class Mostro : public Personaggio{
private:

protected:
    bool increaseLevel(unsigned int ex);

public:
    Mostro(){}

    //p = oro che consegna alla morte
    Mostro(unsigned int lv, string n, unsigned int p, int exp): Personaggio(80, 10, lv, 10, "Mostro", n, p){
        increaseLevel(0);
        setExp(static_cast<unsigned int>(exp)-getExpPoint());
    }

    unsigned int giveUpExp()const;
    unsigned int giveUpCoins()const;
    unsigned int * giveUpLoot()const;

    //abilità
    unsigned int attaccoSemplice();
    unsigned int morsoVampirico();
    unsigned int attaccoPotente();

    int abilita1();
    int abilita2();
    int abilita3();

};

#endif // MOSTRO_H
