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

unsigned int Berserker::attaccoFurioso(){
    return 2*getBaseAttack()*critico()+getLevel();
}
unsigned int Berserker::asciaDiFuoco(){
    return getBaseAttack()*critico()+getLevel()*2;
}
unsigned int Berserker::furiaAssassina(){
    return 3*getBaseAttack()*critico()+getLevel();
}
