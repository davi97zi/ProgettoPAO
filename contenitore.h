#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "Interfacce/personaggio.h"

class Contenitore{
private:
    class Nodo{
    private:
        Personaggio* info;
        Nodo* next;
    public:
        Nodo(): info(0), next(0) {}
        Nodo(Personaggio* i, Nodo* n): info(i), next(n) {}
        ~Nodo(){
            delete info;
            if(next)
                delete next;
        }
        //RIVEDERE (*n.getNext) è una shallow copy
        Nodo(const Nodo& n): info(new Personaggio(*n.getInfo())), next(new Nodo(*n.getNext())) {}
        //RIVEDERE
        Nodo& operator=(const Nodo& n){
            if(this!=&n){
                delete info;
                delete next;
                info=new Personaggio(*n.getInfo());
                next=new Nodo(*n.getNext());
            }
            return *this;
        }

        Personaggio* getInfo() const;
        Nodo* getNext() const;
        //Nodo* setNext(Personaggio* p);

    };
    Nodo* first;

public:
    class Iteratore{
    private:
        Nodo* punt;
    public:
        Iteratore(): punt(0) {}
        ~Iteratore(){
            if (punt)
                delete punt;
        }
        Nodo& operator*() const; //*p
        Nodo* operator->() const; //p
        Iteratore& operator++();
        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
    };
    Contenitore(): first(0) {}
    ~Contenitore(){
        if (first)
            delete first;
    }
    Iteratore addNodo(Personaggio*);
    Iteratore deleteNodo(Iteratore&);



};

#endif // CONTENITORE_H
