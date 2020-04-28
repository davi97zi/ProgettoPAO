#ifndef BATTAGLIA_H
#define BATTAGLIA_H

#include <QWidget>

namespace Ui {
class Battaglia;
}

class Battaglia : public QWidget
{
    Q_OBJECT

public:
    explicit Battaglia(QWidget *parent = 0);
    ~Battaglia();

private:
    Ui::Battaglia *ui;
};

#endif // BATTAGLIA_H
