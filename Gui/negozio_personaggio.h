#ifndef NEGOZIO_PERSONAGGIO_H
#define NEGOZIO_PERSONAGGIO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Negozio_personaggio : public QWidget
{
    Q_OBJECT
private:
    short unsigned int id;
    QLabel * nome;
    QLabel * tipo;
    QLabel * livello;
    QLabel * prezzo;
    QPushButton * assolda;
public:
    explicit Negozio_personaggio(int i, QString n, QString t, int l, int p, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // NEGOZIO_PERSONAGGIO_H
