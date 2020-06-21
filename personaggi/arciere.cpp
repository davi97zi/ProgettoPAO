#include "arciere.h"

Arciere::~Arciere() {}

int Arciere::abilita1()
{
    return static_cast<int>(this->frecciaAppuntita())*(-1);
}

int Arciere::abilita2()
{
    return static_cast<int>(this->frecciaInfuocata())*(-1);
}

int Arciere::abilita3()
{
    return static_cast<int>(this->frecciaPesante())*(-1);
}

bool Arciere::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseMaxHealth(20*(getLevel()-1));
        increaseArmor(3*getLevel());
        increaseAttack(5*(getLevel()-1));
        increaseProbCritico();
        return true;
    }
    else {
        return false;
    }
}

unsigned int Arciere::frecciaAppuntita() const{
    return (20+getBaseAttack())*critico();
}

unsigned int Arciere::frecciaInfuocata() const{
    return 2*getBaseAttack()*critico()+getLevel();
}

unsigned int Arciere::frecciaPesante() const{
    return 3*getBaseAttack()*critico();
}
