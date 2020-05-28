#include "mainwindow.h"
#include <QApplication>

#include "taverna.h"
#include "storico.h"
#include "dungeon.h"
#include "incantesimo.h"

#include "Gui/negozio_widget.h"



using namespace std;

int main(int argc, char *argv[]){
    Incantesimo i("berseker", 3);
    qDebug() << i.getNome();
    qDebug() << i.getString();
    return 0;

/*
    //gui negozio funziona e il sistema dei figli elimina tutto quello che deve
    QApplication a(argc, argv);
    Negozio_widget w;
    w.show();
    return a.exec();
*/
/*
    //lettura da XML e stampa dei dati OK
    Taverna Fandolin;
    qDebug() << "there are people in here who can help you on your quest, you can see:";
    Fandolin.stampaTutti();

    //prendi un personaggio-> ok
    XmlItem Taako=Fandolin.ingaggia("Taako Taaco", 200);

    Fandolin.stampaTutti();


    //lettura da XML e stampa dei dati OK
    Storico storico;
    //qDebug() << "here is the tale of what you did till now: ";
    //storico.stampaStorico();
    std::vector<XmlItem> s;
    s.push_back(XmlItem("scales", "paladino", 5, 3));
    storico.addPartita(QDateTime::currentDateTime().toString(), false, 3, 15, s);//works fine =)

     storico.saveStorico(); //crashes...?

    storico.stampaStorico();


    Dungeon direDices;
    qDebug() << "you are in the dungeon, inside are: ";
    direDices.stampaTutti();
*/
}
