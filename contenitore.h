#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "Interfacce/personaggio.h"
//per test
#include <iostream>
#include <QDebug>


class Contenitore{
friend class Iteratore;
private:
    /*class Nodo;
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
    };*/

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
        //Serve per usare op--
        //Contenitore& parent;
    public:
        //Iteratore(Contenitore& p, Nodo* s=0): punt(s), parent(p) {}
        //Iteratore(const Iteratore& it, Contenitore& p): punt(it.punt), parent(p) {}
        Iteratore(Nodo* s=0): punt(s) {}
        Iteratore(const Iteratore& it): punt(it.punt) {}
        //IL DISTRUTTORE NON SERVE
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
    }
    void addNodo(Personaggio*);
    Iteratore deleteNodo(Iteratore&);
    Iteratore begin() const;
    Iteratore end() const;
    bool vuoto() const;
    //se non lo trova restituisce un iteratore=Contenitore.end()
    Iteratore trovaPersonaggio(QString nome) const;


};

//PER TEST
std::ostream& operator<<(std::ostream&, Contenitore);

#endif // CONTENITORE_H
