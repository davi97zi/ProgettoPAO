#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QWidget* firstWindow;
    QPushButton* gioca;
    QPushButton* storico;
    QSpacerItem* spacer;
    QVBoxLayout* verticalLayout1;

public:
    MainWindow(QWidget *parent = 0);

    void handleButton();
};

#endif // MAINWINDOW_H
