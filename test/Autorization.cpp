#include "mainwindow.h"
#include "Autorization.h"
#include "registration.h"
#include "user.h"
#include "ui_registration.h"
#include "ui_Autorization.h"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"

Autorization::Autorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Autorization)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/MyProject/test/Data/db_test.sqlite");

    if(!db.open()){
        QMessageBox::information(this, "Not connected", "Database not connected");
    }else{
        QMessageBox::information(this, "Connected", "Database is connected");
    }
    ui->setupUi(this);
}

Autorization::~Autorization()
{
    delete ui;
}

void Autorization::on_pushButton_clicked()
{   Registration *w = new Registration();
    this->close();
    w->show();

}


void Autorization::on_pushButton_2_clicked()
{

    QString XLogin=ui->textEdit->toPlainText();
    QString XPassword=ui->textEdit_2->toPlainText();
    QString XPrivileg=ui->comboBox->currentText();

    QSqlQuery query(QSqlDatabase::database());

    if (!query.exec("SELECT * FROM Users")) {
        QMessageBox::information(this, "Error", "Error");
    } else {

    }
    int Find=0;
    while (query.next()) {

        const int STR_EQUL=0;

        QString YLogin = query.value(2).toString();
        QString YPassword = query.value(3).toString();
        QString YPrivileg = query.value(5).toString();
        if(QString::compare(YLogin,XLogin)==STR_EQUL && QString::compare(YPassword,XPassword)==STR_EQUL && QString::compare(YPrivileg,XPrivileg)==STR_EQUL){
            Find=1;
            if(YPrivileg=="Admin"){
            MainWindow *w= new MainWindow();
            this->close();
            w->show();
            }
            else{
            User *w= new User();
            this->close();
            w->show();

            }
        }  

    }
    if(Find!=1){QMessageBox::information(this, "Fail", "Net polzovatelia, nujhna registracia");

   }

}

