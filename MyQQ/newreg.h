#ifndef NEWREG_H
#define NEWREG_H

#include <QWidget>

namespace Ui {
class newreg;
}

class newreg : public QWidget
{
    Q_OBJECT

public:
    explicit newreg(QWidget *parent = 0);
    ~newreg();

private:
    Ui::newreg *ui;
};

#endif // NEWREG_H
