#include "magic_interface.h"

//usato da increaselevel
void MagicInterface::increaseMaxMana(unsigned int addVal){
    maxMana += addVal;
}

unsigned int MagicInterface::getMaxMana() const {return maxMana;}

unsigned int MagicInterface::getMana() const {return mana;}

bool MagicInterface::isThrowable(unsigned int m) const{ //controlla se il mago ha il mana necessario per lanciare l'abilità
    if(mana < m)
        return false;
    return true;
}

//aggiorna il mana dopo il lancio di un'abilità
void MagicInterface::setMana(unsigned int m){
    mana -= m;
}

//per ripristinare il mana alla fine di uno scontro, anche se non è aumentato di livello
void MagicInterface::resetMana(){
    mana = maxMana;
}


unsigned int MagicInterface::getCostoA1() const {return costoManaAbilita1;}
unsigned int MagicInterface::getCostoA2() const {return costoManaAbilita2;}
unsigned int MagicInterface::getCostoA3() const {return costoManaAbilita3;}

void MagicInterface::setCostoA1(unsigned int c) {
    costoManaAbilita1 = c;
}

void MagicInterface::setCostoA2(unsigned int c) {
    costoManaAbilita2 = c;
}

void MagicInterface::setCostoA3(unsigned int c) {
    costoManaAbilita3 = c;
}
