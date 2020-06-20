#include "defence_interface.h"



int DefenceInterface::reducedDamageWithArmor(int damage) const {
    return damage - (damage*static_cast<int>(getArmor()))/100;
}

void DefenceInterface::increaseArmor(unsigned int valAdd){
    setArmor(static_cast<int>(valAdd));
}



void DefenceInterface::buffArmor(){
    setArmor(15*static_cast<int>(getLevel()));
}

void DefenceInterface::setDefaultArmor()
{
    int subVal= static_cast<int>(maxArmor)-static_cast<int>(getArmor());
    setArmor(subVal);
}
