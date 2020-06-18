#ifndef INFO_PERSONAGGIO_STORICO_H
#define INFO_PERSONAGGIO_STORICO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>

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

#endif // INFO_PERSONAGGIO_STORICO_H
