#ifndef INFOPARTITASTORICO_H
#define INFOPARTITASTORICO_H

#include <QWidget>
#include <QVBoxLayout>


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

#endif // INFOPARTITASTORICO_H
