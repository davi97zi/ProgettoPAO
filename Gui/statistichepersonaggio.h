#ifndef STATISTICHEPERSONAGGIO_H
#define STATISTICHEPERSONAGGIO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class StatistichePersonaggio: public QWidget{
    Q_OBJECT
private:
    QWidget* statistiche;
    QVBoxLayout* vertical;
    QHBoxLayout* horizontal;
    QLabel* nome;
    QLabel* tipologia;
    QLabel* livello;
    QLabel* prezzo;

public:
    StatistichePersonaggio(QWidget* parent, const QString& n, const QString& t, const QString& l, const QString& p);

    /*
    void setLabelNome(const QString& n);
    void setLabelTipologia(const QString& n);
    void setLabelLivello(const QString& n);
    void setLabelPrezzo(const QString& n);*/
};

#endif // STATISTICHEPERSONAGGIO_H
