#include "mainwindow.h"
#include <QApplication>
#include "mago.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mago* m = new Mago("aifseiof", 100);
    cout << m->getCostoA1();

    return a.exec();
}
