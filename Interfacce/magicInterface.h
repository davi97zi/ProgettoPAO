#ifndef MAGICINTERFACE_H
#define MAGICINTERFACE_H

#include "personaggio.h"

class MagicInterface: virtual public Personaggio{
private:
    unsigned int maxMana;	//mana disponibile all'inizio dello scontro per ogni mago (massimo) UGUALE PER TUTTI -> usato da increaseLevel() -> aumenta col livello
    unsigned int mana;	//mana che si aggiorna ogni volta che si lancia un'abilità; inizialmente uguale a maxMana
    //costo delle abilita' delle classi figlie (mago, artificiere)

    unsigned int costoManaAbilita1;
    unsigned int costoManaAbilita2;
    unsigned int costoManaAbilita3;
protected:
    virtual void increaseMaxMana(unsigned int addVal);

public:
    /*MagicInterface(unsigned int mH, unsigned int bA, unsigned int lv, unsigned int a, QString t, QString n, unsigned int p, unsigned int m):
        Personaggio(mH, bA, lv, a, t, n, p), maxMana(m), mana(m) {}*/
    MagicInterface(unsigned int m): maxMana(m), mana(m) {}

    unsigned int getMaxMana() const;
    unsigned int getMana() const;
    bool isThrowable(unsigned int m) const;
    void setMana(unsigned int m);
    void resetMana();

    unsigned int getCostoA1() const;
    unsigned int getCostoA2() const;
    unsigned int getCostoA3() const;

    //virtual?
    virtual void setCostoA1(unsigned int c);
    virtual void setCostoA2(unsigned int c);
    virtual void setCostoA3(unsigned int c);
};


#endif // MAGICINTERFACE_H
