#ifndef MAGIC_INTERFACE_H
#define MAGIC_INTERFACE_H

#include "personaggio.h"

class MagicInterface: virtual public Personaggio{
private:
    unsigned int maxMana;	//mana disponibile all'inizio della partita
    unsigned int mana;	//mana che si aggiorna ogni volta che si lancia un'abilità; inizialmente uguale a maxMana
    //costo delle abilita' delle classi figlie (mago, artificiere)
    unsigned int costoManaAbilita1;
    unsigned int costoManaAbilita2;
    unsigned int costoManaAbilita3;

protected:
    virtual void increaseMaxMana(unsigned int addVal);

public:
    MagicInterface(unsigned int m): maxMana(m), mana(m) {}

    unsigned int getMaxMana() const;
    unsigned int getMana() const;
    bool isThrowable(unsigned int m) const;
    void setMana(unsigned int m);
    void resetMana();
    unsigned int getCostoA1() const;
    unsigned int getCostoA2() const;
    unsigned int getCostoA3() const;

    virtual void setCostoA1(unsigned int c);
    virtual void setCostoA2(unsigned int c);
    virtual void setCostoA3(unsigned int c);
};


#endif // MAGIC_INTERFACE_H
