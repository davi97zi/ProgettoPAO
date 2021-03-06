#include "soldato.h"

bool Soldato::increaseLevel(unsigned int newExpPoint){
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseMaxHealth(5*getLevel());
        increaseArmor(4*getLevel());
        increaseAttack(5*getLevel());
        increaseProbCritico();
        return true;
    }
    else{
        return false;
    }
}

int Soldato::abilita1()
{
    return static_cast<int>(this->pugnoFurtivo())*(-1);
}

int Soldato::abilita2()
{
    return static_cast<int>(this->fendente())*(-1);
}

int Soldato::abilita3()
{
    return static_cast<int>(this->coltellata())*(-1);
}

//IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
unsigned int Soldato::pugnoFurtivo() const{
    return 2*getBaseAttack()*critico()+getLevel();
}

unsigned int Soldato::fendente() const{
    return (3*getBaseAttack()*critico()+getLevel())+3;
}

unsigned int Soldato::coltellata() const{
    return 2*getBaseAttack()*critico()+getLevel()*3;
}

//PER TEST
std::ostream &operator<<(std::ostream &os, const Soldato &s)
{
    return os<<"arm= "<<s.getArmor()<<" bAtt= "<<s.getBaseAttack()<<" Exp= "<<s.getExpPoint()<<" lvl= "<<s.getLevel();
}
