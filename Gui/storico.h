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
    QDate* getDate();
public:
    Storico(QWidget* parent);
};

#endif // STORICO_H
