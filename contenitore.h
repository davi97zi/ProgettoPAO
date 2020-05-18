#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "Interfacce/personaggio.h"
//per test
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
        //MODIFICA: messo smartp const&
        Nodo(Personaggio* i, const SmartP& n): info(i), next(n), riferimenti(0) {}
        ~Nodo(){
            /*if(info)
                delete info;
            //modificato
            //era:
            //  if(next->punt)
            //      delete next->punt;
            //
            if(next!=0)
                delete next.punt;*/
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
        Iteratore(Contenitore& p, SmartP s=0): sPunt(s), parent(p) {}
        Iteratore(const Iteratore& it): sPunt(it.sPunt), parent(it.parent) {}
        ~Iteratore(){
            /*if (sPunt.punt)
                delete sPunt.punt;*/
        }
        Personaggio& operator*() const; //*p
        Personaggio* operator->() const; //p
        Iteratore& operator++();
        Iteratore& operator--();
        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
        Iteratore& operator=(const Iteratore&);
    };
    Contenitore(): first(0) {}
    ~Contenitore(){
        /*if (first.punt)
            delete first.punt;*/
    }
    void addNodo(Personaggio*);
    Iteratore deleteNodo(Iteratore&);
    Iteratore begin();
    Iteratore end();
    bool vuoto() const;
    //se non lo trova restituisce un iteratore=Contenitore.end()
    Iteratore trovaPersonaggio(QString nome);

    //Per test
    SmartP getFirst();
    Personaggio* getPersFirst();

};

//PER TEST
std::ostream& operator<<(std::ostream&, Contenitore);

#endif // CONTENITORE_H
