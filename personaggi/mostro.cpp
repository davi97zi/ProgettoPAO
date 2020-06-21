#include "mostro.h"

bool Mostro::increaseLevel(unsigned int ex){
    if(Personaggio::increaseLevel(ex)){
        increaseMaxHealth(60*(getLevel()-1));
        increaseArmor(5*getLevel());
        increaseAttack(10*(getLevel()-1));
        return true;
    }
    else
        return false;
}


unsigned int Mostro::giveUpExp()const{
    if(Personaggio::getDeathState())
        return getExpPoint();
    else
        return 0;
}

unsigned int Mostro::giveUpCoins()const{
    if(Personaggio::getDeathState())
        return getPrezzo();
    else
        return 0;
}


unsigned int * Mostro::giveUpLoot()const{
    if(Personaggio::getDeathState()){
    unsigned int* loot= new unsigned int;
    loot[0]= giveUpExp();
    loot[1]= giveUpCoins();
    return loot;
    }
    else{
        return 0;
    }
}


int Mostro::abilita1()
{
    return static_cast<int>(this->attaccoSemplice())*(-1);
}

int Mostro::abilita2()
{
    return static_cast<int>(this->morsoVampirico())*(-1);
}

int Mostro::abilita3()
{
    return static_cast<int>(this->attaccoPotente())*(-1);
}

//abilità
unsigned int Mostro::attaccoSemplice(){
    unsigned int x= getBaseAttack()*2;
    return x;
}

unsigned int Mostro::morsoVampirico(){
    unsigned int x= getBaseAttack()+getLevel()*15;
    receiveHealing(x);
    return x;
}

unsigned int Mostro::attaccoPotente(){
    unsigned int x= getBaseAttack()+(getLevel()*25);
    return x;
}
