#ifndef SCEGLIAPPLICATIVO_H
#define SCEGLIAPPLICATIVO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

class ScegliApplicativo : public QWidget
{
    Q_OBJECT
private:
    QPushButton* gioca;
    QPushButton* storico;
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

#endif // SCEGLIAPPLICATIVO_H
