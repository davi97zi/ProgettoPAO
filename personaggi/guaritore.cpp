#include "guaritore.h"

bool Guaritore::increaseLevel(unsigned int newExpPoint){
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseArmor(3*getLevel());
        increaseAttack(4*(getLevel()-1));
        increaseMaxHealth(15*(getLevel()-1));
        increaseBlessing();//chiama reset con NEWLevel, in entrambi i casi riporta a "zero" il blessing per la prossima BATTAGLIA
        return true;
    } else
        return false;
}

unsigned int Guaritore::useBlessing(){
    unsigned int smite= getBlessing();
    smite= smite *getLevel();
    return smite;
}

//add or get juice
unsigned int Guaritore::pray(bool use){
    if(!use){
        prayForBlessing();
        return 0;
    }
    else{
        unsigned int smite=getBlessing() +(getLevel());
        resetBlessing();
        return smite;
    }
}

int Guaritore::abilita1()
{
    return static_cast<int>(this->healingWord());
}

int Guaritore::abilita2()
{
    return static_cast<int>(this->smite())*(-1);
}

int Guaritore::abilita3()
{
    return static_cast<int>(this->divineIntervention());
}

unsigned int Guaritore::healingWord(){//usato per guarire se stessi e gli altri
    pray(false);
    unsigned int gain=getLevel()+getBlessing();
    receiveHealing(gain);//guarigione su se stessi
    return gain;//guarigione sugli altri
}

unsigned int Guaritore::smite(){
    return getBaseAttack()*2+pray(true);
}

unsigned int Guaritore::divineIntervention(){//USATO PER RIPORTARE IN VITA UN PERSONAGGIO CADUTO IN BATTAGLIA
    return healingWord()+pray(true);
}
