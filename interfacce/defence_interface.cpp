#include "defence_interface.h"



unsigned int DefenceInterface::reducedDamageWithArmor(unsigned int damage) const {
    return damage - (damage*getArmor())/100;
}

void DefenceInterface::increaseArmor(unsigned int valAdd){
    setArmor(valAdd);
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
    setArmor(15*getLevel());
}

void DefenceInterface::setDefaultArmor()
{
    int subVal= maxArmor-getArmor();
    setArmor(subVal);
}
