#ifndef DEFENCEINTERFACE_H
#define DEFENCEINTERFACE_H

#include "personaggio.h"

class DefenceInterface: virtual public Personaggio{
private:
    unsigned short int turni;
    unsigned int maxArmor;
    static const unsigned short int maxTurni; //aggiunto perchè il prof consigliava sempre di riconoscere le "costanti di classe" negli esercizi
protected:

    virtual unsigned int reducedDamageWithArmor(unsigned int damage) const;

    virtual void increaseArmor(unsigned int valAdd);
    virtual void incrementaTurni();

    //decrementaturni lo invoca ogni abilita del personaggio della classe defenceinterface
    //Turni viene decrementato solo quando il personaggio che ha utlizzato l'abilita BuffArmor e' in uso dall'utente
    void decrementaTurni();
    int getTurno();

public:

    DefenceInterface(unsigned int m): turni(0), maxArmor(m){}//NB turni dovrebbe essere zero?

    unsigned short int getTurni()const;

    //incrementa l'armatura, se non e' disponibile l'abilita (Turni !=0) restituisce false, altrimenti true
    virtual bool buffArmor();


};

#endif // DEFENCEINTERFACE_H

