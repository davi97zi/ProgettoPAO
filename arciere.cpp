#include "arciere.h"

Arciere::~Arciere() {}

unsigned int Arciere::abilita1()
{
    return this->frecciaAppuntita();
}

unsigned int Arciere::abilita2()
{
    return this->frecciaInfuocata();
}

unsigned int Arciere::abilita3()
{
    return this->frecciaPesante();
}

bool Arciere::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseMaxHealth(5*getLevel());
        increaseArmor(3*getLevel());
        increaseAttack(6*getLevel());
        increaseProbCritico();
        return true;
    }
    else {
        return false;
    }
}

//IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
unsigned int Arciere::frecciaAppuntita() const{
    return 2*getBaseAttack()*critico()+getLevel();
}

unsigned int Arciere::frecciaInfuocata() const{
    return 3*getBaseAttack()*critico()+getLevel();
}

unsigned int Arciere::frecciaPesante() const{
    return 2*getBaseAttack()*critico()+getLevel()*2;
}

//PER TEST
std::ostream &operator<<(std::ostream &os, const Arciere &a)
{
    return os<<"arm= "<<a.getArmor()<<" bAtt= "<<a.getBaseAttack()<<" Exp= "<<a.getExpPoint()<<" lvl= "<<a.getLevel();
}
