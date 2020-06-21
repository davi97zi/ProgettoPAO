#ifndef STORICO_H
#define STORICO_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QDateTime>
#include <QStandardItemModel>
#include "../xml/storico_modello.h"
#include "../xml/xml_item.h"
//#include "main_window.h"


class Storico: public QWidget{
    Q_OBJECT

private slots:
    void handleButton();

private:
    QWidget* windowStorico;
    QVBoxLayout* vertical;
    QLabel* titolo;
    QTableWidget* table;
    QPushButton* indietro;

public:
    Storico(QWidget* parent=0);
    void addRow(const StoricoModello::StoricoModelloItem&);

signals:
    void signalReturnToMain();
    void showRowInfo(int);

public slots:
    void returnToMain();
};

#endif // STORICO_H
