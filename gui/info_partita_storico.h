#ifndef INFO_PARTITA_STORICO_H
#define INFO_PARTITA_STORICO_H

#include <QWidget>
#include <QVBoxLayout>
#include "info_personaggio_storico.h"

class InfoPartitaStorico : public QWidget
{
    Q_OBJECT

public:
    explicit InfoPartitaStorico(QWidget *parent = nullptr);
    void addPersonaggio(QString, QString, QString, int);//add 1 personaggio?

private:
    QVBoxLayout * lay;

signals:

public slots:
};

#endif // INFO_PARTITA_STORICO_H
