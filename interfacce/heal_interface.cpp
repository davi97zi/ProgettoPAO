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

void HealInterface::increaseBlessing(){//chiamato da increaseLevel->(!) must be VIRTUAL! al salire di livello
    resetBlessing();//... RIDONDANZA O CHIAREZZA???
}

unsigned int HealInterface::getBlessing()const{//ritorna Blessing come VALORE IN LETTURA, usato per fare check di valore
    return blessing;
}

unsigned int HealInterface::pray(bool use){// può essere usato x accumulare blessing tramite preghiere O per fare "un azione benedetta dalla divinità" azzerando blessing
    if(!use){// add holy juice to tank
        prayForBlessing();
        return 0;
    }
    else{//use holy juice
        unsigned int smite=blessing;//valore da ritornare
        resetBlessing();
        return smite;
    }
}
