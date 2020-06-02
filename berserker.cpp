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

unsigned int Berserker::abilita1(){
    return static_cast<unsigned int>(this->colpoStordente());
}

unsigned int Berserker::abilita2(){
    return this->asciaDiFuoco();
}

unsigned int Berserker::abilita3(){
    return this->furiaAssassina();
}




bool Berserker::colpoStordente(){
    if(getTurno()!=0){
        decrementaTurni();
        return false;
    } else{
        incrementaTurni();
        setMaxArmor(getArmor());
        return true;
    }
}

unsigned int Berserker::asciaDiFuoco() const{
    return getBaseAttack()*critico()+getLevel()*2;
}
unsigned int Berserker::furiaAssassina() const{
    return 3*getBaseAttack()*critico()+getLevel();
}
