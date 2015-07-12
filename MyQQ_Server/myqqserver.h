#ifndef MYQQSERVER_H
#define MYQQSERVER_H

#include <QMainWindow>
//#include "global.h"

namespace Ui {
class MyQQServer;
}

class MyQQServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyQQServer(QWidget *parent = 0);
    ~MyQQServer();

private:
    Ui::MyQQServer *ui;

    int m_nlistenfd;
    int m_nconnfd;
};

#endif // MYQQSERVER_H
