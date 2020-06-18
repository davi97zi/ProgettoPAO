#ifndef PALADINO_H
#define PALADINO_H

#include "../interfacce/defence_interface.h"
#include "../interfacce/heal_interface.h"

class Paladino: public DefenceInterface, public HealInterface{
private:
    //x ottenere blessing & ottenere scudo in uno
    unsigned int shieldOfFaith();
    //per ottenere blessing & guarire
    unsigned int layOfHands();
    //per dare BOTTE
    unsigned int ultimateSmite();
public:
    Paladino(QString nome, unsigned int ex);

    bool increaseLevel(unsigned int newExpPoints) override;

    //NB devo ridefinire qui pray && buffArmor
    virtual void buffArmor() override;

    virtual unsigned int pray(bool use) override;




    int abilita1() override;
    int abilita2() override;
    //scegliere e sistemare quale mettere in abilità 3 tra buffarmour e la cura
    int abilita3() override;
};

#endif // PALADINO_H
