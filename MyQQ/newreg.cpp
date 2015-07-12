#include "newreg.h"
#include "ui_newreg.h"

newreg::newreg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newreg)
{
    ui->setupUi(this);
}

newreg::~newreg()
{
    delete ui;
}
