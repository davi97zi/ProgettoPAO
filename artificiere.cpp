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

unsigned int Artificiere::bombardaMaxima(){
    unsigned int dmg = getBaseAttack() + 10*getLevel() + 2*critico();
    if(isThrowable(getCostoA1()) == true){
        setMana(getCostoA1());
        return dmg;
    } else
        return 0;
}

unsigned int Artificiere::rainOfSpells(){
    unsigned int dmg = getBaseAttack() + 15*getLevel() + 8*critico();
    if(isThrowable(getCostoA2()) == true){
        setMana(getCostoA2());
        return dmg;
    } else
        return 0;
}

unsigned int Artificiere::autodistruzione(){ //shotta ma ti uccide
    unsigned int dmg = getBaseAttack() + 10000;
    if(isThrowable(getCostoA3()) == true){
        setMana(getCostoA3());
        receiveDamage(dmg);
        return dmg;
    } else
        return 0;
}

