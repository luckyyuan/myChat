#ifndef GLOBAL_H
#define GLOBAL_H

#include <QSqlDatabase>
#include <QMessageBox>

/* 建立database. */
QSqlDatabase g_sqlitedbConn = QSqlDatabase::addDatabase("QSQLITE", "sqlitedb");

/*********************************************************
 * 名称:printMsg
 * 描述:打印消息
 * 注意:目前只打印出告警消息，后面可作补充
 *********************************************************/
void printMsg(QString strMsgType, QString strMsgDetail)
{
    QMessageBox::warning(NULL, strMsgType, strMsgDetail);
}

/*********************************************************
 * 名称:
 * 描述:
 * 注意:
 *********************************************************/


enum server_usertype_en
{
    USER_TYPE_SERVER,
    USER_TYPE_CLIENT
};

typedef struct
{
    QString strUserName;
    QString strPassword;
    int nUserType;
    int y;
}server_userinfo_st;

#define SERVER_PORT_DEFAULT 2048


#endif // GLOBAL_H

