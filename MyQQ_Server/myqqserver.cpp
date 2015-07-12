#include "global.h"
#include "myqqserver.h"
#include "ui_myqqserver.h"

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

MyQQServer::MyQQServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyQQServer)
{
    ui->setupUi(this);

    sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT_DEFAULT);

    if ((m_nlistenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printMsg("error", "create socket failed.");
        this->close();
        return;
    }

    if (bind(m_nlistenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        printMsg("error", "bind socket failed.");
        this->close();
        return;
    }





}

MyQQServer::~MyQQServer()
{
    delete ui;
}
