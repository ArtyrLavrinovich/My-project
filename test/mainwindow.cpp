#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{



    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString XName=ui->textEdit_3->toPlainText();
    QString XNumber=ui->textEdit_4->toPlainText();

    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO testtable (Name, Number) VALUES (:Name, :Number)");
    query.bindValue(":Number", XNumber);
    query.bindValue(":Name", XName);
    if (!query.exec())
    {
        qDebug() << "Failed to insert data into table";
    }

}



void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec ("Select * FROM testtable");
    while (query.next()) {
        QString Name = query.value(1).toString();
        QString Number = query.value(2).toString();

        Name.append(" | "+ Number);

        ui->textEdit->append(Name);

    }

}


void MainWindow::on_pushButton_3_clicked()
{


}


void MainWindow::on_pushButton_4_clicked()
{


    QSqlQuery query(QSqlDatabase::database());
    QString DelNumber=ui->textEdit_5->toPlainText();
    query.exec ("DELETE from testtable where Number='11'");


}


void MainWindow::on_pushButton_5_clicked()
{

    QString NewName = ui->textEdit_2->toPlainText();
    QSqlQuery query(QSqlDatabase::database());
    query.exec("UPDATE testtable SET Name='" + NewName + "' where Number=11");
    }


void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->clear();
}

