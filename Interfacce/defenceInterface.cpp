#include "defenceInterface.h"

const unsigned short int DefenceInterface::maxTurni=3;

unsigned int DefenceInterface::reducedDamageWithArmor(unsigned int damage) const {
    return damage - (damage*getArmor())/100;
}

void DefenceInterface::increaseArmor(unsigned int valAdd){
    setArmor(valAdd);
}

void DefenceInterface::incrementaTurni(){
    turni=maxTurni;
}

void DefenceInterface::decrementaTurni(){
    if(turni!=0){
        turni--;
    }
    else{
        int subVal= maxArmor-getArmor();
        setArmor(subVal);
    }
}

int DefenceInterface::getTurno(){return turni;}


unsigned short DefenceInterface::getTurni() const
{
    return turni;
}

bool DefenceInterface::buffArmor(){
    if(turni!=0)
        return false;
    setArmor(5*getLevel());
    incrementaTurni();
    return true;
}
