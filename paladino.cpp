#include "paladino.h"

Paladino::Paladino(QString nome, unsigned int ex):
    Personaggio(30, 20, 1, 15, "Paladino", nome, 4),
    DefenceInterface(30), HealInterface(){
        increaseLevel(ex);
}

bool Paladino::increaseLevel(unsigned int newExpPoint){
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseArmor(2*getLevel());
        increaseAttack(4+getLevel());
        increaseMaxHealth(5+(getLevel()*2));
        setMaxArmor(getArmor());//nb manca un setmaxarmorrrrr
        increaseBlessing();//chiama reset con NEWLevel, in entrambi i casi riporta a "zero" il blessing per la prossima BATTAGLIA
        return true;
    } else
        return false;
}

bool Paladino::buffArmor(){
    if(getTurni()!=0)
        return false;
    else{
        setMaxArmor(getArmor()+getBlessing()*getLevel());
        return true;
    }
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
    return static_cast<int>(this->shieldOfFaith())*(-1);
}

int Paladino::abilita2()
{
    return static_cast<int>(this->layOfHands())*(-1);
}

int Paladino::abilita3()
{
    return static_cast<int>(this->ultimateSmite())*(-1);
}

bool Paladino::shieldOfFaith(){
    pray(false);
    /*if(buffArmor()==false)
        throw 0;*/
    return buffArmor();
}

//per ottenere blessing & guarire
unsigned int Paladino::layOfHands(){
    pray(false);
    unsigned int gain=getMaxArmor()+getBlessing()+getLevel();
    receiveHealing(gain);
    return gain;
}

//per dare BOTTE
unsigned int Paladino::ultimateSmite(){
    unsigned int dmg=pray(true)+getBaseAttack()+getLevel();
    return dmg;
}
