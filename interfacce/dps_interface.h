#ifndef DPS_INTERFACE_H
#define DPS_INTERFACE_H

#include "personaggio.h"
#include <cstdlib>
#include <ctime>

class DpsInterface: virtual public Personaggio{
private:
    unsigned int probCritico;

protected:
    virtual void increaseProbCritico();
    unsigned int critico() const;

public:
    DpsInterface(unsigned int p): probCritico(p) {}
};

#endif // DPS_INTERFACE_H
