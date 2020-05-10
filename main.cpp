#include "mainwindow.h"
#include <QApplication>

#include "taverna.h"

using namespace std;

int main(int argc, char *argv[]){
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Taverna Fandolin;
    qDebug() << "there are people in here who can help you on your quest, you can see:";
    Fandolin.stampaTutti();
    //return a.exec();
    return 0;
}
