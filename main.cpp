#include <QApplication>
#include "controller/controller.h"
#include "gui/info_personaggio_storico.h"
#include "gui/info_partita_storico.h"
#include "xml/storico_modello.h"
#include "contenitore.h"

#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]){
    srand(static_cast<unsigned int>(time(NULL)));
    QApplication a(argc, argv);

    Controller C;

    return a.exec();
}
