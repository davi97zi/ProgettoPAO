#ifndef PARTITA_H
#define PARTITA_H

#include <QWidget>

namespace Ui {
class Partita;
}

class Partita : public QWidget
{
    Q_OBJECT

public:
    explicit Partita(QWidget *parent = 0);
    ~Partita();

private:
    Ui::Partita *ui;
};

#endif // PARTITA_H
