#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <client.h>
#include <iostream>
#include <QStandardItemModel>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Txtstatus->setText("Listo");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Bsubmit_clicked()
{
    QString str = ui->Txtline->text();
    string str1 = str.toStdString();
    char temp[1024];
    string str2 = Client("192.168.100.11",8070, strcpy(temp, str1.c_str()));
    if(str=="" or str2 == "err"){
        ui->Txtstatus->setText("ERROR: The request hadn't the right syntaxis");
        QMessageBox::information(this, "HADB","There were a error \n Check your request");
    }else{
        ui->Txtline->setText("");
        ui->RBDisk->setChecked(true);
        ui->RBMaster->setChecked(true);
        ui->RBQuery->setChecked(true);

    }
}

void MainWindow::on_BHelp_clicked()
{
    QMessageBox::information(this, "Help","Here are few examples of what you need to do: \n"
                                          "CREATE TABLE ESTUDIANTES (NOMBRE STRING, ID INT, PRIMARY KEY ID)\n"
                                          "DROP TABLE DEPTO \n"
                                          "INSERT INTO ESTUDIANTES VALUES (Gerardo, 2016243868) \n"
                                          "SELECT * FROM orders");
}



void MainWindow::on_BVisual_clicked()
{
   //string request = Client("192.168.100.11",8070,"SELECT * FROM ESCUELA");
   string request = "NOMBRE,Juan,Manuel,Gerardo,Antonio,Hernaldo:ID,s001,s002,s003,s004,s005:NOTA,88,95,74,15,35" ;
   int init = 0;
   int flag = 0;
   int colum = 0;
   int row = 0;

   QStandardItemModel *model = new QStandardItemModel(sumRows(request),sumCol(request),this);
   for(int i=0;i < request.length()-1;i++){
       if(init == 0 and request[i] == ','){
           model->setHorizontalHeaderItem(colum, new QStandardItem(QString::fromStdString(request.substr(init,i))));
           colum++;
           init = i+1;
           row = 0;
       }else if(request[i] == ':'){
           flag = 1;
           init = i+1;
       }else if(flag == 1 and request[i] == ','){
           model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(request.substr(init,i))));
           colum++;
           row = 0;
           init = i+1;
       }else if(request[i] == ',' and flag == 0){
           QStandardItem *str = new QStandardItem(QString::fromStdString(request.substr(init,i)));
           model->setItem(row, colum,str);
           init = i+1;
           row++;
       }

   }
   ui->DataTable->setModel(model);

}

int MainWindow::sumCol(string req){
    int j =0;
    for(int i =0;i < req.length();i++){
        if(req[i]== ':'){
            j++;
        }
    }
    return j;
}
int MainWindow::sumRows(string req){
    int j=0;
    for(int i =0; i<req.length();i++){
        if(req[i] != ':'){
            if (req[i] == ',')
                j++;

         }else{
             j++;
             break;

    }
   }
   return j-1;
}
/*
void MainWindow::makeTable(int row, int col,string req){
    int flag = 0;
    int init = 0;
    int colum = 0;
    QStandardItemModel *model = new QStandardItemModel(row, col, this);
    for(int i = 0; i< req.length();i++){
        if(init == 0 and req[i]== ','){
            model->setHorizontalHeaderItem(column, new QStandardItem(QString(req.substr(init,i)));
            colum++;
        }
        if(req == ':'){
            flag = 1;
            init = i+1;
        }
        if(flag == 1 and req[i] == ','){
            model->setHorizontalHeaderItem(i, new QStandardItem(QString(req.substr(init,i)));
            colum++;
        }
    }
    ui->DataTable->setModel(model);

}*/
