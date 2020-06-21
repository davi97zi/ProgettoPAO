#include "main_window.h"


MainWindow::MainWindow(QWidget* central, QWidget *parent) : firstWindow(central),
    QMainWindow(parent)
{
    resize(500,350);
    setCentralWidget(firstWindow);
}

void MainWindow::resetCentralWidget(){
    setCentralWidget(new ScegliApplicativo);
}
