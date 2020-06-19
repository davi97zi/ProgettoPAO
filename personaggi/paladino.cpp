#include "paladino.h"

Paladino::Paladino(string nome, unsigned int ex):
    Personaggio(30, 20, 1, 15, "Paladino", nome, 4),
    DefenceInterface(15), HealInterface(){
        increaseLevel(ex);
}

bool Paladino::increaseLevel(unsigned int newExpPoint){
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseArmor(2*getLevel());
        increaseAttack(4+getLevel());
        increaseMaxHealth(5+(getLevel()*2));
        setArmor(getArmor());//nb manca un setmaxarmorrrrr
        increaseBlessing();//chiama reset con NEWLevel, in entrambi i casi riporta a "zero" il blessing per la prossima BATTAGLIA
        return true;
    } else
        return false;
}

void Paladino::buffArmor(){
    setArmor(getArmor()+getBlessing()*getLevel());
}

unsigned int Paladino::pray(bool use){
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

int Paladino::abilita1()
{
    return static_cast<int>(this->shieldOfFaith());
}

int Paladino::abilita2()
{
    return static_cast<int>(this->layOfHands());
}

int Paladino::abilita3()
{
    return static_cast<int>(this->ultimateSmite())*(-1);
}

unsigned int Paladino::shieldOfFaith(){
    pray(false);
    buffArmor();
    return 1;
}

//per ottenere blessing & guarire
unsigned int Paladino::layOfHands(){
    pray(false);
    unsigned int gain=getArmor()+getBlessing()+getLevel();
    receiveHealing(gain);
    return gain;
}

//per dare BOTTE
unsigned int Paladino::ultimateSmite(){
    unsigned int dmg=pray(true)+getBaseAttack()+getLevel();
    return dmg;
}
