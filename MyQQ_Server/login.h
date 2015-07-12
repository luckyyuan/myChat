#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "myqqserver.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

public slots:
    void LoginServer();
    void Cancel();

private:
    Ui::Login *ui;
    MyQQServer m_qqser;
};

#endif // LOGIN_H
