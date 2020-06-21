#ifndef ARCIERE_H
#define ARCIERE_H

#include "../interfacce/dps_interface.h"

class Arciere: public DpsInterface{
private:
    unsigned int frecciaAppuntita() const;
    unsigned int frecciaInfuocata() const;
    unsigned int frecciaPesante() const;
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Arciere(string nome, unsigned int ex): Personaggio (70, 15, 1, 8, "Arciere", nome, 0), DpsInterface(10){
        increaseLevel(ex);
    }
    virtual ~Arciere();


    int abilita1();
    int abilita2();
    int abilita3();
};

#endif // ARCIERE_H
