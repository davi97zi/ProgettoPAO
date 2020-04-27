#include "defenceInterface.h"

const unsigned short int DefenceInterface::maxTurni=3;

unsigned int DefenceInterface::reducedDamageWithArmor(unsigned int damage) const {
    return damage - (damage*maxArmor)/100;
}

void DefenceInterface::increaseMaxArmor(unsigned int valAdd){
    maxArmor = valAdd;
}

void DefenceInterface::incrementaTurni(){
    turni=maxTurni;
}

void DefenceInterface::decrementaTurni(){
    if(turni!=0){
        turni--;
    setMaxArmor(getArmor());
    }
}

int DefenceInterface::getTurno(){return turni;}

void DefenceInterface::setMaxArmor(unsigned int arm){
    maxArmor=arm;//NB is different from all other setters...
}

unsigned int DefenceInterface::getMaxArmor() const{
    return maxArmor;
}

unsigned short DefenceInterface::getTurni() const
{
    return turni;
}

bool DefenceInterface::buffArmor(){
    if(turni!=0)
        return false;
    setMaxArmor(getArmor()+maxTurni*getLevel());
    return true;
}
