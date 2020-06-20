#include "main_window.h"
#include <QDebug>


MainWindow::MainWindow(QWidget* central, QWidget *parent) : firstWindow(central),
    QMainWindow(parent)
{
    resize(500,350);
    setCentralWidget(firstWindow);
}

void MainWindow::resetCentralWidget(){
    setCentralWidget(new ScegliApplicativo);
}
