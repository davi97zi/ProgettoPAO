#ifndef DPSINTERFACE_H
#define DPSINTERFACE_H

#include "personaggio.h"
#include <cstdlib> //per rand()
#include <ctime> //per time()

class DpsInterface: virtual public Personaggio{
private:
    //***UNSIGNED INT***
    unsigned int probCritico;

protected:
    //il metodo per aumentare la probabilit� si chiama INCREASE anche se di fatto decrementa il parametro per farlo.
    virtual void increaseProbCritico();
    unsigned int critico() const;

public:
    //***usa il costruttore standard di personaggio***
    DpsInterface(unsigned int p): probCritico(p) {}
};

#endif // DPSINTERFACE_H
