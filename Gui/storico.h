#ifndef STORICO_H
#define STORICO_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class Storico: public QWidget{
    Q_OBJECT
private slots:
    void handleButton();
private:
    QWidget* windowStorico;
    QVBoxLayout* vertical;
    QLabel* titolo;
    QTableWidget* table;
    QPushButton* moreInfo;

    int getFileRows();
    QString getDate();
    QTime getTime();
public:
    Storico(QWidget* parent=0);
};

#endif // STORICO_H
