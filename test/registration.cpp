#include "mainwindow.h"
#include "Autorization.h"
#include "registration.h"
#include "ui_registration.h"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"

Registration::Registration(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_2_clicked()
{
    QString XLogin=ui->textEdit->toPlainText();
    QString XPassword=ui->textEdit_2->toPlainText();
    QString XPrivileg=ui->comboBox->currentText();

    QSqlQuery query(QSqlDatabase::database());

    query.prepare("INSERT INTO Users (Login, Password,Privileg_name) VALUES (:Login, :Password, :Privileg_name)");
    query.bindValue(":Login", XLogin);
    query.bindValue(":Password", XPassword);
    query.bindValue(":Privileg_name", XPrivileg);

    if (!query.exec())
    {
        qDebug() << "Failed to insert data into table";
    }

    if (XPrivileg=="Admin"){
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("INSERT INTO Users (id_Privileg) VALUES (:id_Privileg)");
        query.bindValue(":id_Privileg", 1);

        if (!query.exec())
        {
            qDebug() << "Failed to insert data into table";
        }

    }
    else{
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("INSERT INTO Users (id_Privileg) VALUES (:id_Privileg)");
        query.bindValue(":id_Privileg", 2);
        if (!query.exec())
        {
            qDebug() << "Failed to insert data into table";
        }

    }

    Autorization *w=new Autorization();
    w->show();
}

