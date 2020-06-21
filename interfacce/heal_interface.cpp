#include "heal_interface.h"

void HealInterface::prayForBlessing(){//chiamato da azione determinata da classe derivata, aumenta blessing
    blessing++;
}

void HealInterface::resetBlessing(){
    blessing=getLevel()-1; // da personaggio
}

unsigned int HealInterface::askForBlessing(){//chiamato per usare il blessing accumulato e fare il reset del blessing
    unsigned int result=blessing;
    resetBlessing();
    return result;
}

void HealInterface::increaseBlessing(){
    resetBlessing();
}

unsigned int HealInterface::getBlessing()const{
    return blessing;
}

unsigned int HealInterface::pray(bool use){// può essere usato x accumulare blessing
    if(!use){
        prayForBlessing();
        return 0;
    }
    else{
        unsigned int smite=blessing;
        resetBlessing();
        return smite;
    }
}
