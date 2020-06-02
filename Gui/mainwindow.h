#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

class MainWindow : public QMainWindow
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

public slots:
    void handleButton();
    void remakeMain();

signals:
    void signalBottone(QString);

};

#endif // MAINWINDOW_H
