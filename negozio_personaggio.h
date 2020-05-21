#ifndef NEGOZIO_PERSONAGGIO_H
#define NEGOZIO_PERSONAGGIO_H

#include <QWidget>
#include <QLabel>
class Negozio_personaggio : public QWidget
{
    Q_OBJECT
private:
    QLabel * nome;
    QLabel * tipo;
    QLabel *
public:
    explicit Negozio_personaggio(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // NEGOZIO_PERSONAGGIO_H
