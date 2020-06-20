#ifndef MOSTRO_H
#define MOSTRO_H

#include "../interfacce/personaggio.h"
#include <QDebug>

class Mostro : public Personaggio{
private:

protected:
    bool increaseLevel(unsigned int ex);

public:
    Mostro(){}
    //costruttore potrebbe assegnare un X+30 come exp
    //-> X permette di determinare il livello (e sarà quindi <100 * #battaglia>);
    //->30*getLevel() per determinare quanti numeri exp vengono passati come bottino
    //mHp,bAtk,exp,arm, type, nome, prz
    //p = oro che da
    Mostro(unsigned int lv, string n, unsigned int p, int exp): Personaggio(100, 10, lv, 10, "Mostro", n, p){
        increaseLevel(0);
        setExp(exp-getExpPoint());
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

    int abilita1();
    int abilita2();
    int abilita3();

};

#endif // MOSTRO_H
