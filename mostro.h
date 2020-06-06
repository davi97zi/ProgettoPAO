#ifndef MOSTRO_H
#define MOSTRO_H

#include "Interfacce/personaggio.h"

class Mostro : public Personaggio{
private:

protected:
    bool increaseLevel(unsigned int ex);

public:
    Mostro(){}
    //costruttore potrebbe assegnare un X+30 come exp
    //-> X permette di determinare il livello (e sarà quindi <100 * #battaglia>);
    //->30*getLevel() per determinare quanti numeri exp vengono passati come bottino
    //mHp,bAtk,exp,arm, type, nm, prz
    Mostro(unsigned int ex, QString n, unsigned int p): Personaggio(500, 10, ex, 10, "mostro", n, p){
        increaseLevel(0);
    }

    //LOOT! functions
    unsigned int giveUpExp()const;

    unsigned int giveUpCoins()const;

    //possibile funzione che ritorni entrambi? probably wont be used
    unsigned int * giveUpLoot()const;
    //abilità
    unsigned int attaccoSemplice();
    unsigned int morsoVampirico();

    unsigned int attaccoPotente();

};

#endif // MOSTRO_H
