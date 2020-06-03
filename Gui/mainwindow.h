#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include "scegliapplicativo.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget* firstWindow;

public:
    MainWindow(QWidget* central=new ScegliApplicativo, QWidget *parent = 0);

    void resetCentralWidget();

public slots:
    //void handleButton();
    //void remakeMain();
/*
signals:
    void signalBottone(QString);*/

};

#endif // MAINWINDOW_H
