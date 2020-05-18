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



Personaggio &Contenitore::Iteratore::operator*() const{
    return *sPunt->info;
}

Personaggio *Contenitore::Iteratore::operator->() const{
    return sPunt->info;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator++(){
    /* VECCHIA IMPLEMENTAZIONE
    if(sPunt->next!=0)
        sPunt=sPunt->next;
    return *this;
    */
    if(sPunt!=0)
        sPunt=sPunt->next;
    return *this;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator--(){
//OK
//aggiunto l'if perchè altrimenti se uso -- su un iteratore che punta a first diventa un ++
    Iteratore it=parent.begin();
    if(it.sPunt!=this->sPunt){
        while(it.sPunt->next!=0 && it.sPunt.punt->next!=this->sPunt){
            ++it;
        }
        sPunt=it.sPunt;
    }
    return *this;
}

bool Contenitore::Iteratore::operator==(const Contenitore::Iteratore & it) const{
    return sPunt==it.sPunt;
}

bool Contenitore::Iteratore::operator!=(const Contenitore::Iteratore & it) const{
    return sPunt!=it.sPunt;
}


Contenitore::Iteratore &Contenitore::Iteratore::operator=(const Contenitore::Iteratore &it){
    sPunt=it.sPunt;
    parent=it.parent;
    return *this;
}

void Contenitore::addNodo(Personaggio *p){
    first=SmartP(new Nodo(p,first));
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
    if(it.sPunt!=0){
        //se l'iteratore punta al primo nodo
        if(it.sPunt==first){
            ++it2;
            //sposto first
            first=it.sPunt.punt->next;
            //stacco it dalla lista
            it.sPunt.punt->next=0;
        }
        else{
            --it2;
            //se it non punta all'ultimo elemento della lista
            if(it.sPunt.punt->next!=0){
                //sposto il puntatore next del precedente al successivo di it
                it2.sPunt.punt->next=it.sPunt.punt->next;
                //stacco it dalla lista
                it.sPunt.punt->next=0;
                ++it2;
            }
            //se it punta all'ultimo elemento della lista
            else{
                //setto il puntatore next del precedente a 0
                it2.sPunt.punt->next=0;
            }
        }
        //FUNZIONA MA VA BENE? elimino info, next è già 0
        //delete it.sPunt.punt;
        delete it.sPunt.punt->info;
    }
    return it2;
}

Contenitore::Iteratore Contenitore::begin(){
    Iteratore it(*this, first);
    return it;
}

Contenitore::Iteratore Contenitore::end(){
    Iteratore it(*this, 0);
    return it;
}

bool Contenitore::vuoto() const{
    return first==0;
}

Contenitore::Iteratore Contenitore::trovaPersonaggio(QString nome){
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

//per test
Contenitore::SmartP Contenitore::getFirst()
{
    return first;
}
//per test
Personaggio* Contenitore::getPersFirst()
{
    return first.punt->info;
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
