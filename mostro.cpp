#include "mostro.h"

bool Mostro::increaseLevel(unsigned int ex){
    if(Personaggio::increaseLevel(ex)){
        increaseMaxHealth(5*getLevel());
        increaseArmor(5*getLevel());
        increaseAttack(5*getLevel());
        return true;
    }
    else
        return false;
}

//LOOT! functions
unsigned int Mostro::giveUpExp()const{
    if(Personaggio::getDeathState())
        return getExpPoint(); //? i guess
    else
        return 0;
}

unsigned int Mostro::giveUpCoins()const{
    if(Personaggio::getDeathState())
        return getPrezzo();
    else
        return 0;
}

//possibile funzione che ritorni entrambi? probably wont be used
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
    unsigned int x= getBaseAttack()*2*(getLevel()); // NB evitare le divisioni! al lvl 1 possono voler dire che si fanno 0 danni!
    return x;
}

unsigned int Mostro::morsoVampirico(){
    unsigned int x= getBaseAttack()*2*(getLevel());
    receiveHealing(x);
    return x;
}

unsigned int Mostro::attaccoPotente(){
    unsigned int x= getBaseAttack()*2*(2*getLevel());
    return x;
}
