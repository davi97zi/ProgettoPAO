#ifndef PALADINO_H
#define PALADINO_H

#include "../interfacce/defence_interface.h"
#include "../interfacce/heal_interface.h"

class Paladino: public DefenceInterface, public HealInterface{
private:
    //x ottenere blessing & ottenere scudo
    unsigned int shieldOfFaith();
    //per ottenere blessing & guarire
    unsigned int layOfHands();
    //attacco
    unsigned int ultimateSmite();
public:
    Paladino(string nome, unsigned int ex);

    bool increaseLevel(unsigned int newExpPoints) override;
    virtual void buffArmor() override;
    virtual unsigned int pray(bool use) override;

    int abilita1() override;
    int abilita2() override;
    int abilita3() override;
};

#endif // PALADINO_H
