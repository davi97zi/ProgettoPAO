#ifndef SCEGLI_APPLICATIVO_H
#define SCEGLI_APPLICATIVO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>


class ScegliApplicativo : public QWidget
{
    Q_OBJECT

private:
    QPushButton* gioca;
    QPushButton* storico;
    QLabel* titolo;
    QSpacerItem* spacer;
    QVBoxLayout* verticalLayout1;

public:
    ScegliApplicativo(QWidget *parent = 0);

public slots:
    void handleButton();
    void remakeMain();

signals:
    void signalBottone(QString);

};

#endif // SCEGLI_APPLICATIVO_H
