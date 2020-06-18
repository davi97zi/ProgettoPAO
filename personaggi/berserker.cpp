#include "berserker.h"

//***aumentare i punti esperienza necessari per aumentare di livello nei personaggi complessi??***
bool Berserker::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
        if(Personaggio::increaseLevel(newExpPoint) == true){
            increaseMaxHealth(6*getLevel());
            increaseArmor(4*getLevel());
            increaseAttack(7*getLevel());
            increaseProbCritico();
            return true;
        }
        else{
            return false;
        }
}

int Berserker::abilita1(){
    return static_cast<int>(this->furiaAssassina())*(-1);
}

int Berserker::abilita2(){
    return static_cast<int>(this->asciaDiFuoco())*(-1);
}

int Berserker::abilita3(){
    buffArmor();
    return 1;
}



unsigned int Berserker::asciaDiFuoco() const{
    return getBaseAttack()*critico()+getLevel()*2;
}
unsigned int Berserker::furiaAssassina() const{
    return 3*getBaseAttack()*critico()+getLevel();
}
