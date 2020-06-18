#include "artificiere.h"
#include <iostream>

bool Artificiere::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
  if(Personaggio::increaseLevel(newExpPoint) == true){
    increaseMaxHealth(5*getLevel());
    increaseArmor(4*getLevel());
    increaseAttack(10*getLevel());
    increaseProbCritico();
    increaseMaxMana(10*getLevel());
    return true;
  }
  else {
      return false;
  }
}

int Artificiere::abilita1(){
    return static_cast<int>(this->bombardaMaxima())*(-1);
}

int Artificiere::abilita2()
{
    return static_cast<int>(this->rainOfSpells())*(-1);
}

int Artificiere::abilita3()
{
    return static_cast<int>(this->autodistruzione())*(-1);
}

unsigned int Artificiere::bombardaMaxima(){
    unsigned int dmg = getBaseAttack() + 10*getLevel() + 2*critico();
    if(isThrowable(getCostoA1()) == true){
        setMana(getCostoA1());
        return dmg;
    } else
        throw 5;
}

unsigned int Artificiere::rainOfSpells(){
    unsigned int dmg = getBaseAttack() + 15*getLevel() + 8*critico();
    if(isThrowable(getCostoA2()) == true){
        setMana(getCostoA2());
        return dmg;
    } else
        throw 5;
}

unsigned int Artificiere::autodistruzione(){ //shotta ma ti uccide
    unsigned int dmg = getBaseAttack() + 10000;
    if(isThrowable(getCostoA3()) == true){
        setMana(getCostoA3());
        receiveDamage(dmg);
        return dmg;
    } else
        throw 5;
}

