#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
#include "scegli_applicativo.h"
#include "storico.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget* firstWindow;

public:
    MainWindow(QWidget* central=new ScegliApplicativo, QWidget *parent = 0);
    void resetCentralWidget();

};

#endif // MAIN_WINDOW_H
