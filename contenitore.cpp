#include "contenitore.h"


Contenitore::SmartP::SmartP(const Contenitore::SmartP& s): punt(s.punt){
    if(punt)
        punt->riferimenti++;
}

Contenitore::SmartP::~SmartP(){
    if(punt){
        punt->riferimenti--;
        if(punt->riferimenti==0)
            delete punt;
    }
}

Contenitore::SmartP &Contenitore::SmartP::operator=(const Contenitore::SmartP& s){
    if(this!=&s){
        Nodo*t=punt;
        punt=s.punt;
        if(punt)
            punt->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti==0)
                delete t;
        }
    }
    return *this;
}

Contenitore::Nodo &Contenitore::SmartP::operator*() const{
return *punt;
}

Contenitore::Nodo *Contenitore::SmartP::operator->() const{
return punt;
}

bool Contenitore::SmartP::operator==(const Contenitore::SmartP &s) const{
    return punt==s.punt;
}

bool Contenitore::SmartP::operator!=(const Contenitore::SmartP &s) const{
    return punt!=s.punt;
}



Personaggio &Contenitore::Iteratore::operator*() const{
    return *sPunt->info;
}

Personaggio *Contenitore::Iteratore::operator->() const{
    return sPunt->info;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator++(){
    sPunt=sPunt->next;
    return *this;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator--(){
//sembra quasi OK
    Iteratore it=parent.begin();
    while(it.sPunt!=0 || it.sPunt.punt->next==this->sPunt){
        ++it;
    }
    sPunt=it.sPunt;
    return *this;
}

bool Contenitore::Iteratore::operator==(const Contenitore::Iteratore & it) const{
    return sPunt==it.sPunt;
}

bool Contenitore::Iteratore::operator!=(const Contenitore::Iteratore & it) const{
    return sPunt!=it.sPunt;
}

void Contenitore::addNodo(Personaggio *p){
    first=SmartP(new Nodo(p,first));
}

//sembra OK; restituisce il successivo di quello eliminato FORSE
Contenitore::Iteratore Contenitore::deleteNodo(Contenitore::Iteratore & it){
    Iteratore it2=it;
    if(it.sPunt!=0){
        SmartP(it.sPunt);
        --it2;
        it2.sPunt.punt->next=it.sPunt.punt->next;
        delete it.sPunt.punt;
    }
    return ++it2;
}

Contenitore::Iteratore Contenitore::begin(){
    Iteratore it(*this, first);
    return it;
}

Contenitore::Iteratore Contenitore::end(){
    Iteratore it(*this, 0);
    return it;
}
