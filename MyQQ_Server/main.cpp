//#include "myqqserver.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyQQServer w;    
    Login w;
    w.show();

    return a.exec();
}
