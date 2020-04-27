#include "mainwindow.h"
#include <QApplication>
#include "mago.h"
#include "artificiere.h"
#include "soldato.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Mago* m = new Mago("aifseiof", 100);
    cout << m->getCostoA1() << " " << m->getExpPoint() << " " << m->getLevel() << endl;

    Soldato* s = new Soldato("priodsoj", 8);
    cout << s->getArmor() << " " << s->getExpPoint() << " " << s->getLevel() << endl;

    Artificiere* ar = new Artificiere("jjj", 4356);
    cout << ar->getCostoA1() << " " << ar->getExpPoint() << " " << ar->getLevel();
   // return a.exec();
    return 0;
}
