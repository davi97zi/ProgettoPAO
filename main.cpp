#include "mainwindow.h"
#include <QApplication>

#include "mostro.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

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
    return 0;
}
