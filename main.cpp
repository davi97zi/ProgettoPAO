#include "mainwindow.h"
#include <QApplication>

#include "mago.h"
#include "artificiere.h"
#include "soldato.h"
#include "tank.h"
#include "guaritore.h"
#include "berserker.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    /*QApplication a(argc, argv);
    MainWindow w;
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

    Soldato* s=new Soldato("sss", 115);
    cout<<s->getBaseAttack()<<' '<<s->getLevel()<<' '<<s->getExpPoint()<<endl;

    Berserker* b=new Berserker("bbb", 15);
    cout<<b->getBaseAttack()<<' '<<b->getLevel()<<' '<<b->getExpPoint()<<endl;
    Berserker* b2=new Berserker("bbb", 115);
    cout<<b2->getBaseAttack()<<' '<<b2->getLevel()<<' '<<b2->getExpPoint()<<endl;

    //return a.exec();
    return 0;
}
