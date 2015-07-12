#include "login.h"
#include "global.h"
//#include "myqqserver.h"

#include "ui_login.h"
#include <QSqlQuery>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    /* 限制用户名的输入只能是数字，且第一位不能是0 */
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->m_textAdminName);
    ui->m_textAdminName->setValidator(validator);

    connect(ui->m_btnServerLogin, SIGNAL(clicked()), this, SLOT(LoginServer()));
    connect(ui->m_btnServerCancel, SIGNAL(clicked()), this, SLOT(close()));
}

Login::~Login()
{
    delete ui;
}

/*********************************************************
 * 名称:LoginServer
 * 描述:登录服务器时触发，对登录信息进行校验
 * 注意:如果是第一次登录，则创建管理员信息，否则进行校验
 *********************************************************/
void Login::LoginServer()
{
    QString strAdminName = ui->m_textAdminName->text();
    QString strAdminPsw = ui->m_textAdminPsw->text();

    g_sqlitedbConn.setDatabaseName("chat.sqlite");
    if (!g_sqlitedbConn.open())
    {
        printMsg("warning", "database open failed, please check the connection.");
        close();
    }

    /* 数据库第一次使用时创建数据表 */
    QSqlQuery loginQry(g_sqlitedbConn);
    loginQry.exec("create table usertable ( "
                  " username nchar(12) not null, "
                  " password nchar(40) not null, "
                  " usertype int, "
                  " noticedate date, "
                  " noticetitle nchar(50), "
                  " noticedetail nchar(500), "
                  " loginip nchar(20), "
                  " logindate date, "

                  " primary key(username))");

    if (!loginQry.isActive())
    {
        printMsg("error", "create data table failed.");
        this->close();
        return;
    }

    loginQry.prepare("select * from usertable where usertype = :usertype");
    loginQry.addBindValue(":usertype", (int)USER_TYPE_SERVER);
    loginQry.exec();
    if (!loginQry.isActive())
    {
        printMsg("warning", "query table failed.");
        this->close();
        return;
    }

    /* 存在管理員信息則核对用户信息 */
    if (loginQry.next())
    {
        QString strDBName = loginQry.value(0).toString();
        QString strDBPsw = loginQry.value(1).toString();
        if (strAdminName == strDBName && strAdminPsw == strDBPsw)
        {
            m_qqser.show();
            this->close();
        }
        else
        {
            printMsg("warning", "username or password error!\nplease try again!");
        }
    }
    /* 不存在就是第一次登录，将输入的用户信息写入数据库并打开服务器 */
    else
    {
        loginQry.prepare("insert into usertable(username, password, usertype) values (:username, :password, :usertype)");
        loginQry.bindValue(":username", strAdminName);
        loginQry.bindValue(":password", strAdminPsw);
        loginQry.bindValue(":userinfo", USER_TYPE_SERVER);
        loginQry.exec();
        if (!loginQry.isActive())
        {
            printMsg("warning", "insert data failed.");
            this->close();
            return;
        }

        m_qqser.show();
        this->close();
    }

}

void Login::Cancel()
{
    exit(0);
}
