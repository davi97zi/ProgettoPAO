#include "contenitore.h"

Personaggio &Contenitore::Iteratore::operator*() const{
    return *punt->info;
}

Personaggio *Contenitore::Iteratore::operator->() const{
    return punt->info;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator++(){
    if(punt)
        punt=punt->next;
    return *this;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator--(){
    if(punt){
        if(punt->prev)
            punt=punt->prev;
    }
    return *this;
}

bool Contenitore::Iteratore::operator==(const Contenitore::Iteratore & it) const{
    return punt==it.punt;
}

bool Contenitore::Iteratore::operator!=(const Contenitore::Iteratore & it) const{
    return punt!=it.punt;
}


Contenitore::Iteratore &Contenitore::Iteratore::operator=(const Contenitore::Iteratore &it){
    punt=it.punt;
    return *this;
}

void Contenitore::addNodo(Personaggio *p){
    Nodo* n=new Nodo(p,first,0);
    first=n;
    if(first->next){
        first->next->prev=first;
    }
}


//restituisce il successivo di quello eliminato
Contenitore::Iteratore Contenitore::deleteNodo(Contenitore::Iteratore & it){
    Iteratore it2=it;
    if(it.punt!=0){
        if(it.punt==first){
            ++it2;
            first=it.punt->next;
            it.punt->next=0;
        }
        else{
            --it2;
            if(it.punt->next!=0){
                it2.punt->next=it.punt->next;
                it.punt->next=0;
                ++it2;
            }
            else{
                it2.punt->next=0;
            }
        }
        delete it.punt;
    }
    return it2;
}

Contenitore::Iteratore Contenitore::begin() const{
    Iteratore it(first);
    return it;
}

Contenitore::Iteratore Contenitore::end() const{
    Iteratore it(0);
    return it;
}

bool Contenitore::vuoto() const{
    return first==0;
}

Contenitore::Iteratore Contenitore::trovaPersonaggio(string nome) const{
    Iteratore it=this->begin();
    bool sent=false;
    while(it!=this->end() && sent==false){
        if(it->getNome()==nome)
            sent=true;
        else
            ++it;
    }
    if(it.punt==0)
        throw 0;
    return it;
}
