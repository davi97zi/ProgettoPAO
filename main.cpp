#include "mainwindow.h"
#include <QApplication>

#include "mago.h"
#include "artificiere.h"
#include "soldato.h"
#include "tank.h"
#include "guaritore.h"
#include "berserker.h"
#include "contenitore.h"

//da togliere poi?
#include <cstdlib>
#include <ctime>

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    //QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/

    /*Mago* m = new Mago("aifseiof", 100);
    cout << m->getCostoA1() << " " << m->getExpPoint() << " " << m->getLevel() << endl;

    Tank* t = new Tank("Malphite", 230);
    cout << "Danno abilita' 2: " << t->schiacciasassi() << " Armor: " << t->getArmor()<< endl;

    Artificiere* ar = new Artificiere("jjj", 200);
    cout << ar->getCostoA1() << " " << ar->getExpPoint() << " " << ar->getLevel() << endl;

    Guaritore* g = new Guaritore("fff", 100, 2);
    cout << g->getArmor() << endl;
    cout << g->getBaseAttack() << " LIV: " << g->getLevel() << endl;*/




    //NOTA: critico() FUNZIONA MA VA MESSA LA RIGA SEGUENTE NEL MAIN (O IN PARTITA) PER FARLO FUNZIONARE
    srand(static_cast<unsigned int>(time(NULL)));





    Soldato* s=new Soldato("ss1", 115);
    cout<<"s=> "<<s->getBaseAttack()<<' '<<s->getLevel()<<' '<<s->getExpPoint()<<endl;
    cout<<"s confronto cout=> "<<s->getArmor()<<' '<<s->getBaseAttack()<<' '<<s->getDeathState()<<endl;
    cout<<"s=> "<<*s<<endl;
    delete s;

    Soldato* s2=new Soldato("ss2", 0);
    cout<<"s2=> "<<*s2<<endl;

    Soldato* s3=new Soldato("ss3", 526);
    cout<<"s3=> "<<*s3<<endl;
    Mago* m = new Mago("aifseiof", 100);
    cout <<"mago= "<<*m<< endl;

    Contenitore Pers;
    Pers.addNodo(s2);
    Pers.addNodo(s3);
    Pers.addNodo(m);

    //cout<<Pers<<endl;

    //Contenitore::Iteratore it(Pers); //QUESTO FUNZIONA
    //Contenitore::Iteratore it2(it); //QUESTO FUNZIONA
    Contenitore::Iteratore it4(Pers.begin());
    Contenitore::Iteratore it3=Pers.begin();


    //cout<<it3->getBaseAttack()<<endl;
    cout<<it4->getBaseAttack()<<endl;
    ++it4;
    cout<<"IT++ "<<it4->getBaseAttack()<<endl;
    ++it4;

    cout<<"IT++ "<<it4->getBaseAttack()<<endl;

    //++it4;
    //++it4;
    //cout<<"IT++ "<<it4->getBaseAttack()<<endl;

    //cout<<it4->getBaseAttack()<<endl; //qui it4 punta a 0, bisogna evitare che venga fatto il get->dovrebbe dare seg. fault
    //it4=Pers.begin(); //ora si può fare


    --it4;
    cout<<"IT-- "<<it4->getBaseAttack()<<endl;
    --it4;
    cout<<"IT-- "<<it4->getBaseAttack()<<endl;
    //it4=Pers.begin();
    //cout<<"restart"<<it4->getBaseAttack()<<endl;
    //++it4;
    //cout<<"IT++ "<<it4->getBaseAttack()<<endl;
    --it4;
    cout<<"IT-- "<<it4->getBaseAttack()<<endl;
    --it4;
    cout<<"IT-- "<<it4->getBaseAttack()<<endl;



    //  TEST DEL DELETE :)
    cout<<"Pers PRE delete: "<<Pers<<endl;
    ++it4;
    ++it4;
    cout<<"test del delete (punta all'ultimo): "<<it4->getArmor()<<endl;
    it3=Pers.deleteNodo(it4);
    cout<<"delete fatta: "<<it4->getArmor()<<endl;
    cout<<"Pers POST delete: "<<Pers<<endl;

    //come prima stampa s2 anche se l'ho cancellato ma in realtà è eliminato
    //cout<<*s2<<endl;
    Contenitore::Iteratore iter=Pers.trovaPersonaggio("aifseiof");
    cout<<iter->getBaseAttack()<<endl;

    return 0;
}
