//#include "gui/main_window.h"
#include <QApplication>
#include "controller/controller.h"
#include "gui/info_personaggio_storico.h"
#include "gui/info_partita_storico.h"
#include "xml/storico_modello.h"
#include "contenitore.h"

//da togliere poi?
#include <cstdlib>
#include <ctime>
#include <iostream>


int main(int argc, char *argv[]){
    //NOTA: critico() FUNZIONA MA VA MESSA LA RIGA SEGUENTE NEL MAIN (O IN PARTITA) PER FARLO FUNZIONARE
    //KEEP HERE??
    srand(static_cast<unsigned int>(time(NULL)));
    QApplication a(argc, argv);

    Controller C;

    return a.exec();
}
