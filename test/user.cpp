#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}
