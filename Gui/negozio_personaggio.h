#ifndef NEGOZIO_PERSONAGGIO_H
#define NEGOZIO_PERSONAGGIO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QDebug>

class Negozio_personaggio : public QWidget
{
    Q_OBJECT
private:
    //short unsigned int id;
    QLabel * nome;
    QLabel * tipo;
    QLabel * livello;
    QLabel * prezzo;
    QPushButton * assolda;

private slots:

public:
    Negozio_personaggio(){}
    explicit Negozio_personaggio(int i, QString n, QString t, int l, int p, QWidget *parent = nullptr);
    ~Negozio_personaggio(){qDebug() << "personaggio eliminato";}

signals:
    void personaggioAcquistato(int);

public slots:
    void comunicaPersonaggio();
};

#endif // NEGOZIO_PERSONAGGIO_H
