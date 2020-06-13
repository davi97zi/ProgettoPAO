#include "tank.h"

bool Tank::increaseLevel(unsigned int newExpPoint){
    if(Personaggio::increaseLevel(newExpPoint) == true){
        increaseMaxHealth(20*getLevel());
        increaseArmor(10*getLevel());
        //increaseArmor(15*getLevel());
        increaseAttack(5*getLevel());
        return true;
    }
    else
        return false;
}

int Tank::abilita1(){
    return static_cast<int>(this->schiacciasassi())*(-1);
}

int Tank::abilita2(){
    return static_cast<int>(this->jackhammer())*(-1);

}

int Tank::abilita3(){
    return static_cast<int>(this->scudo());
}

unsigned int Tank::schiacciasassi() const{
    return (getBaseAttack() + 2*(getMaxHealth()-static_cast<unsigned int>(getHealth()))); //danni in base alla vita mancante: meno vita (health) + danni
}
unsigned int Tank::jackhammer() const{
    return (getBaseAttack() + 2*(getArmor())); //danni in base all'armor: +armor (base, no MaxArmor) + danni
}

bool Tank::scudo(){
    if(getTurno()!=0){
        buffArmor();
        decrementaTurni();
        return true;
    } else{
        //incrementaTurni() ?
        setArmor(getArmor());
        return false;
    }
}
