#ifndef PALADINO_H
#define PALADINO_H

#include "Interfacce/personaggio.h"
#include "Interfacce/defenceInterface.h"
#include "Interfacce/healInterface.h"

class Paladino: public DefenceInterface, public HealInterface{
public:
    Paladino(QString nome, unsigned int ex);

    bool increaseLevel(unsigned int newExpPoints) override;

    //NB devo ridefinire qui pray && buffArmor
    virtual bool buffArmor() override;

    virtual unsigned int pray(bool use)override;

    //abilità
    //x ottenere blessing & ottenere scudo in uno
    bool shieldOfFaith();

    //per ottenere blessing & guarire
    unsigned int layOfHands();

    //per dare BOTTE
    unsigned int ultimateSmite();
};

#endif // PALADINO_H
