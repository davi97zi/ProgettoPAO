#ifndef PALADINO_H
#define PALADINO_H

#include "Interfacce/defenceInterface.h"
#include "Interfacce/healInterface.h"

class Paladino: public DefenceInterface, public HealInterface{
private:
    //x ottenere blessing & ottenere scudo in uno
    bool shieldOfFaith();
    //per ottenere blessing & guarire
    unsigned int layOfHands();
    //per dare BOTTE
    unsigned int ultimateSmite();
public:
    Paladino(QString nome, unsigned int ex);

    bool increaseLevel(unsigned int newExpPoints) override;

    //NB devo ridefinire qui pray && buffArmor
    virtual bool buffArmor() override;

    virtual unsigned int pray(bool use) override;




    int abilita1() override;
    int abilita2() override;
    int abilita3() override;
};

#endif // PALADINO_H
