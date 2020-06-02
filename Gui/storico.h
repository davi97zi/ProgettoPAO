#ifndef STORICO_H
#define STORICO_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

#include "../xml/storicoModello.h"

class Storico: public QWidget{
    Q_OBJECT
private slots:
    void handleButton();
private:
    QWidget* windowStorico;
    QVBoxLayout* vertical;
    QLabel* titolo;
    QTableWidget* table;
    //QPushButton* moreInfo;
    QPushButton* indietro;
    int getFileRows();
    QString getDate();
    QTime getTime();
public:
    Storico(QWidget* parent=0);
    void addRow(const StoricoModello::StoricoModelloItem&);

signals:
    void returnToMain();
};

#endif // STORICO_H
