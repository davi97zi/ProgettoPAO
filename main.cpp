#include "mainwindow.h"
#include <QApplication>

//da togliere poi?
#include <cstdlib>
#include <ctime>

#include "Controller/controller.h"
#include "Gui/infopersonaggiostorico.h"
#include "Gui/infopartitastorico.h"
#include "contenitore.h"
#include <iostream>

#include "xml/storicoModello.h"
using namespace std;

int main(int argc, char *argv[]){
    //NOTA: critico() FUNZIONA MA VA MESSA LA RIGA SEGUENTE NEL MAIN (O IN PARTITA) PER FARLO FUNZIONARE
    //KEEP HERE??
    //srand(static_cast<unsigned int>(time(NULL)));
    QApplication a(argc, argv);


    /*Soldato* s=new Soldato("ss1", 115);
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

    cout<<Pers<<endl;*/
    Controller C;

    return a.exec();
}

/*
 * //QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mostro* boss= new Mostro(100, "Vlad", 2);

    cout << "prepare to meet the " << boss->getLevel() << " " << boss->getTipoPersonaggio().QString::toStdString() << " "<< boss->getNome().QString::toStdString() << "\nNOW FIGHT!!!\n";

    cout <<"his hp is: " << boss->getMaxHealth() << endl;
    cout << boss->getNome().QString::toStdString() << " attacks for " << boss->getBaseAttack()<< endl;
    boss->receiveDamage(100);
    cout << "you attack, the moster hp goes to " << boss->getHealth() << "/" << boss->getMaxHealth()<< endl;
    boss->morsoVampirico();
    cout <<"the monster used vampire bite you lost " <<boss->attaccoSemplice() << " and he healed and has now " << boss->getHealth() << "/" << boss->getMaxHealth()<< endl;


    //battaglia
    //cheat: we kill him dead
    boss->receiveDamage(100000);
    cout << "you oneshot the monster! " << boss->getHealth() << "the boss is dead?";

    if(boss->getDeathState()){ //victory: loot
        cout << "you won\n";
        cout << boss->getNome().QString::toStdString() << " was a " << boss->getLevel() << " level monster with " << boss->getExpPoint() << " exp and an armor of" << boss->getArmor();
        cout <<"\nhe surrenders:\n";
        cout << boss->giveUpExp() << endl;
        cout << boss->giveUpCoins() << endl;

        unsigned int * chest= boss->giveUpLoot();
        cout << "in a chest you find: " << chest[0] << " exp and " <<chest[1] << "coins!\n";
    }
    else{//loss: loot box is empty
        cout << "you lost!\n";
        cout << boss->getNome().QString::toStdString() << " was a " << boss->getLevel() << " level monster with " << boss->getExpPoint() << " exp and an armor of" << boss->getArmor();
        cout <<"\nhe surrenders:\n";
        cout << boss->giveUpExp() << endl;
        cout << boss->giveUpCoins() << endl;

        unsigned int * chest= boss->giveUpLoot();
        cout << "in a chest you find: " << chest[0] << " exp and " <<chest[1] << "coins!\n";
    }
    //return a.exec();

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

    Arciere* a=new Arciere("sas", 0);
    cout<<a->abilita1()<<endl;
    cout<<a->abilita2()<<endl;
    cout<<a->abilita3()<<endl;
*/
