#include "mago.h"

bool Mago::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
  if(Personaggio::increaseLevel(newExpPoint) == true){
    increaseMaxHealth(5*getLevel());
    increaseArmor(3*getLevel());
    increaseAttack(6*getLevel());
    increaseMaxMana(15*getLevel());
    resetMana();
    return true;
  }
  else {
      resetMana();
      return false;
  }
}

int Mago::abilita1()
{
    return static_cast<int>(this->expelliarmus())*(-1);
}

int Mago::abilita2()
{
    return static_cast<int>(this->expectoPatronum())*(-1);
}

int Mago::abilita3()
{
    return static_cast<int>(this->avadaKedavra())*(-1);
}

//ogni abilità ha un parametro m che indica il mana necessario per lanciarla o è meglio metterlo come paramentro interno alla funzione?
unsigned int Mago::expelliarmus(){ //abilità1, sempre disponibile
    unsigned int dmg = getBaseAttack() + 10*getLevel();
    if(isThrowable(getCostoA1()) == true){
        setMana(getCostoA1()); //aggiorno il mana
        return dmg;
    } else
        throw 5;
}

unsigned int Mago::expectoPatronum(){ //abilità2, costa 2 turni, fa danni e guarisce il mago
    unsigned int dmg = getBaseAttack() + 18*getLevel();
    if(isThrowable(getCostoA2()) == true){
        receiveHealing(5*getLevel(), false); //guarisce il mago
        setMana(getCostoA2());
        return dmg;
    } else
        throw 5;
}

unsigned int Mago::avadaKedavra(){	//abilità speciale, costa 3 turni, uccide in un colpo solo il nemico
    unsigned int dmg = getBaseAttack() + 1000; //indicativo, deve oneshottare il nemico
    if(isThrowable(getCostoA3()) == true){
        setMana(getCostoA3());
        return dmg;
    } else
        throw 5;
}
