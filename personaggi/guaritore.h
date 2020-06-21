#ifndef GUARITORE_H
#define GUARITORE_H

#include "../interfacce/heal_interface.h"

class Guaritore: public HealInterface{
private:
    unsigned int healingWord();//usato per guarire se stessi e gli altri
    unsigned int smite(); //usato per attacco benedetto
    unsigned int divineIntervention();//USATO PER RIPORTARE IN VITA UN PERSONAGGIO CADUTO IN BATTAGLIA
protected:
    virtual bool increaseLevel(unsigned int newExpPoints);
public:
    Guaritore(string nome, unsigned int ex): Personaggio(95, 8, 1, 10, "Guaritore", nome, 0), HealInterface(){
        increaseLevel(ex);
    }

    virtual unsigned int useBlessing();
    virtual unsigned int pray(bool use);


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // GUARITORE_H
