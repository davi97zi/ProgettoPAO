#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "Interfacce/personaggio.h"
//per test addNodo()
#include <iostream>

class Contenitore{
friend class Iteratore;
private:
    class Nodo;

    //sembra OK
    class SmartP{
    public:
        Nodo* punt;
        SmartP(Nodo*p=0): punt(p){
            if (punt)
                punt->riferimenti++;
        }
        SmartP(const SmartP&);
        ~SmartP();
        SmartP& operator=(const SmartP&);
        Nodo& operator*()const;
        Nodo* operator->()const;
        bool operator==(const SmartP&)const;
        bool operator!=(const SmartP&)const;
    };

    class Nodo{       
    public:
        Personaggio* info;
        SmartP next;
        int riferimenti;
        Nodo(): info(0), next(0), riferimenti(0) {}
        Nodo(Personaggio* i, SmartP n): info(i), next(n), riferimenti(0) {}
        ~Nodo(){
            if(info)
                delete info;
            if(next.punt)
                delete next.punt;
        }
    };
    SmartP first;

public:
    class Iteratore{
    friend class Contenitore;
    private:
        SmartP sPunt;
        //Serve per usare begin()
        Contenitore& parent;
    public:
        Iteratore(Contenitore& p, SmartP s=0): sPunt(s), parent(p) {std::cout<<"normale";}
        //AGGIUNTO IL COSTRUTTORE DI COPIA
        Iteratore(const Iteratore& it): sPunt(it.sPunt), parent(it.parent) {std::cout<<"copia";}
        ~Iteratore(){
            if (sPunt.punt)
                delete sPunt.punt;
        }
        Personaggio& operator*() const; //*p
        Personaggio* operator->() const; //p
        Iteratore& operator++();
        Iteratore& operator--();
        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
    };
    Contenitore(): first(0) {}
    ~Contenitore(){
        if (first.punt)
            delete first.punt;
    }
    void addNodo(Personaggio*);
    Iteratore deleteNodo(Iteratore&);
    Iteratore begin();
    Iteratore end();

    //Per test
    SmartP getFirst();
    Personaggio* getPersFirst();



};

#endif // CONTENITORE_H
