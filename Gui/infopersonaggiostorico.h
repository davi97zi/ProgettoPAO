#ifndef INFOPERSONAGGIOSTORICO_H
#define INFOPERSONAGGIOSTORICO_H

#include <QWidget>
#include <QLabel>

class InfoPersonaggioStorico : public QWidget{
    Q_OBJECT
public:
    InfoPersonaggioStorico(QString, QString, QString, int, QWidget *parent = nullptr);

private:
    QLabel * nome;
    QLabel * tipo;
    QLabel * livello;

signals:

public slots:
};

#endif // INFOPARTITASTORICO_H
