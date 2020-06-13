#include "defenceInterface.h"



unsigned int DefenceInterface::reducedDamageWithArmor(unsigned int damage) const {
    return damage - (damage*getArmor())/100;
}

void DefenceInterface::increaseArmor(unsigned int valAdd){
    setArmor(static_cast<int>(valAdd));
}



/*void DefenceInterface::decrementaTurni(){
    if(turni!=0){
        turni--;
    }
    else{
        int subVal= maxArmor-getArmor();
        setArmor(subVal);
    }
}*/

//int DefenceInterface::getTurno(){return turni;}




void DefenceInterface::buffArmor(){
    setArmor(15*static_cast<int>(getLevel()));
}

void DefenceInterface::setDefaultArmor()
{
    unsigned int subVal= maxArmor-getArmor();
    setArmor(static_cast<int>(subVal));
}
