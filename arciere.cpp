#include "arciere.h"

Arciere::~Arciere() {}

bool Arciere::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
    if(newExpPoint + getExpPoint() >= 100){
        Personaggio::increaseLevel(newExpPoint);
        increaseMaxHealth(5*getLevel());
        increaseArmor(3*getLevel());
        increaseAttack(6*getLevel());
        increaseProbCritico();
        return true;
    }
    else {
        return false;
    }
}

//IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
unsigned int Arciere::frecciaAppuntita(){
    return 2*getBaseAttack()*critico()+getLevel();
}

unsigned int Arciere::frecciaInfuocata(){
    return 3*getBaseAttack()*critico()+getLevel();
}

unsigned int Arciere::frecciaPesante(){
    return 2*getBaseAttack()*critico()+getLevel()*2;
}
