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
    QApplication a(argc, argv);
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
    cout<<"s post delete=> "<<*s<<endl;
    //***VA BENE CHE s ORA PUNTA ALLO STESSO DI s2?***
    Soldato* s3=new Soldato("ss3", 526);
    cout<<"s3=> "<<*s3<<endl;
    Mago* m = new Mago("aifseiof", 100);
    cout <<"mago= "<< m->getArmor() << " " << m->getBaseAttack() << " " << m->getDeathState() << endl;

    Contenitore Pers;
    Pers.addNodo(s2);
    Pers.addNodo(s3);
    Pers.addNodo(m);
    cout<<"ok"<<endl;


    Contenitore::Iteratore it(Pers); //QUESTO FUNZIONA
    Contenitore::Iteratore it2(it); //QUESTO FUNZIONA
    cout<<endl<<"getfirst: "<<Pers.getPersFirst()<<endl; //stampa l'indirizzo
    //Contenitore::Iteratore it3(Pers, Pers.getFirst()); //DOPO QUESTO SI BLOCCA PER QUALCHE MOTIVO
    cout<<endl<<"ok2"<<endl;
    Contenitore::Iteratore it4=Pers.begin();
    cout<<endl<<"ok3"<<endl;
    cout<<it4->getBaseAttack()<<endl; //funziona
    cout<<"1"<<endl;
    ++it4; //funziona
    cout<<"2"<<endl;
    cout<<"crasha dopo questo"<<endl;
    cout<<it4->getBaseAttack()<<endl; //funziona
    ++it4;
    cout<<"3"<<endl;
    cout<<it4->getBaseAttack()<<endl;
    cout<<"sssss"<<endl;
    //++it4;
    //cout<<it4->getBaseAttack()<<endl;
    //cout<<it4->getBaseAttack()<<endl; //qui it4 punta a 0, bisogna evitare che venga fatto il get->dovrebbe dare seg. fault
    //it4=Pers.begin(); //non si può usare perchè serve l'operator=


    //cout<<it4->getBaseAttack()<<endl;
    --it4; //operator-- non va
    cout<<it4->getBaseAttack()<<endl;
    --it4;
    cout<<it4->getBaseAttack()<<endl;

    // !!CRASHA OGNI VOLTA alla fine!!


    return a.exec();
}
