#ifndef CONTENITORE_H
#define CONTENITORE_H

#include "interfacce/personaggio.h"


class Contenitore{
friend class Iteratore;
private:
    class Nodo{       
    public:
        Personaggio* info;
        Nodo* next;
        Nodo* prev;
        Nodo(): info(0), next(0), prev(0) {}
        Nodo(Personaggio* i, Nodo* n, Nodo*p=0): info(i), next(n), prev(p) {}
        ~Nodo(){
            if(info)
                delete info;
            if(next)
                delete next;
        }
    };
    Nodo* first;

public:
    class Iteratore{
    friend class Contenitore;
    private:
        Nodo* punt;
    public:
        Iteratore(Nodo* s=0): punt(s) {}
        Iteratore(const Iteratore& it): punt(it.punt) {}
        Personaggio& operator*() const;
        Personaggio* operator->() const;
        Iteratore& operator++();
        Iteratore& operator--();
        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
        Iteratore& operator=(const Iteratore&);
    };
    Contenitore(): first(0) {}

    void addNodo(Personaggio*);
    Iteratore deleteNodo(Iteratore&);
    Iteratore begin() const;
    Iteratore end() const;
    bool vuoto() const;
    //se non lo trova restituisce un iteratore=Contenitore.end()
    Iteratore trovaPersonaggio(string nome) const;


};

#endif // CONTENITORE_H
