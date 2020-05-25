#ifndef INFO_MATCH_H
#define INFO_MATCH_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class InfoMatch: public QWidget{
    Q_OBJECT
private:
    QLabel* personaggio;
    QLabel* mostro;
    QLabel* livelloPersonaggio;
    QLabel* livelloMostro;
    QVBoxLayout* vertical;

public:
    InfoMatch(QWidget* parent);

    QVBoxLayout* setLayoutPersonaggio();

    QVBoxLayout* setLayoutMostro();
};

#endif // INFO_MATCH_H
