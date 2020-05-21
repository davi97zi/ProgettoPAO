#ifndef STORICO_H
#define STORICO_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>

class Storico: public QWidget{
    Q_OBJECT
private slots:
    void rowSelected(int nRow, int nCol);
private:
    QWidget* windowStorico;
    QVBoxLayout* vertical;
    QLabel* titolo;
    QLabel* info;
    QTableWidget* table;
    int getFileRows();
    QDate* getDate();
public:
    Storico(QWidget* parent);
};

#endif // STORICO_H
