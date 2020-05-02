#include "mainwindow.h"
#include <QApplication>

#include "mago.h"
#include "artificiere.h"
#include "soldato.h"
#include "tank.h"
#include "guaritore.h"
#include "berserker.h"
//da togliere poi
#include <cstdlib>
#include <ctime>

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




    //NOTA: critico() FUNZIONA MA VA MESSA LA RIGA SEGUENTE NEL MAIN (O IN PARTITA) PER FARLO FUNZIONARE
    srand(static_cast<unsigned int>(time(NULL)));





    Soldato* s=new Soldato("sss", 115);
    cout<<s->getBaseAttack()<<' '<<s->getLevel()<<' '<<s->getExpPoint()<<endl;

    delete s;
    Soldato* s2=new Soldato("sss", 0);
    cout<<s->getBaseAttack()<<' '<<s->getLevel()<<' '<<s->getExpPoint()<<endl;
    cout<<s2->getBaseAttack()<<' '<<s2->getLevel()<<' '<<s2->getExpPoint()<<endl;


    return 0;
}
