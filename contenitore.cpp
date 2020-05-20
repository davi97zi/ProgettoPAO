#include "contenitore.h"


/*

Contenitore::SmartP::SmartP(const Contenitore::SmartP& s): punt(s.punt){
    if(punt)
        punt->riferimenti++;
}

Contenitore::SmartP::~SmartP(){
    if(punt){
        punt->riferimenti--;
        if(punt->riferimenti==0)
            delete punt;
        //N.B.: (dal libro) è la delete standard di nodo che richiama (ricorsivamente) il distruttore di smartp
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
            //N.B.: (dal libro) è la delete standard di nodo che richiama (ricorsivamente) il distruttore di smartp
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

*/


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
//OK
//aggiunto l'if perchè altrimenti se uso -- su un iteratore che punta a first diventa un ++
    /*Iteratore it=parent.begin();
       if(it.punt!=this->punt){
           while(it.punt->next!=0 && it.punt->next!=this->punt){
               ++it;
           }
           punt=it.punt;
       }*/
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
    //parent=it.parent;
    return *this;
}

void Contenitore::addNodo(Personaggio *p){
    first=new Nodo(p,first,0);
    if(first->next)
        first->next->prev=first;
}


//OK; restituisce il successivo di quello eliminato
Contenitore::Iteratore Contenitore::deleteNodo(Contenitore::Iteratore & it){
    /*Iteratore it2=it;
    if(it.sPunt!=0){
        SmartP(it.sPunt);
        --it2;
        it2.sPunt.punt->next=it.sPunt.punt->next;
        delete it.sPunt.punt;
    }
    return ++it2;*/

    Iteratore it2=it;
    //se esiste l'iteratore svolgo la funzione, altrimenti restituisco l'iteratore
    if(it.punt!=0){
        //se l'iteratore punta al primo nodo
        if(it.punt==first){
            ++it2;
            //sposto first
            first=it.punt->next;
            //stacco it dalla lista
            it.punt->next=0;
        }
        else{
            --it2;
            //se it non punta all'ultimo elemento della lista
            if(it.punt->next!=0){
                //sposto il puntatore next del precedente al successivo di it
                it2.punt->next=it.punt->next;
                //stacco it dalla lista
                it.punt->next=0;
                ++it2;
            }
            //se it punta all'ultimo elemento della lista
            else{
                //setto il puntatore next del precedente a 0
                it2.punt->next=0;
            }
        }
        //FUNZIONA MA VA BENE? elimino info, next è già 0
        //delete it.sPunt.punt;
        delete it.punt;
    }
    return it2;
}

Contenitore::Iteratore Contenitore::begin() const{
    //Iteratore it(*this, first);
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

Contenitore::Iteratore Contenitore::trovaPersonaggio(QString nome) const{
    Iteratore it=this->begin();
    bool sent=false;
    while(it!=this->end() && sent==false){
        if(it->getNome()==nome)
            sent=true;
        else
            ++it;
    }
    return it;
}



//PER TEST
std::ostream &operator<<(std::ostream &os, Contenitore c)
{
    int a=1;
    //NON posso usare il cout dei personaggi perchè non si può accedere ad sPunt dall'iteratore
    for(Contenitore::Iteratore it=c.begin(); it!=c.end(); ++it){
        os<<"personaggio "<<a<<"= Arm: "<<it->getArmor()<<" lvl: "<<it->getLevel()<<" ";
        a++;
    }
    return os;
}
