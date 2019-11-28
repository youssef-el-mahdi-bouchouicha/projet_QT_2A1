#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"rv.h"
#include"rlog.h"
#include"suppv.h"

#include"affv.h"
#include"affl.h"
#include"suppl.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    rv RV;
    RV.setModal(true);
    RV.exec();
}



void MainWindow::on_pushButton_9_clicked()
{
  Rlog rl;
  rl.setModal(true);
  rl.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    affv av;
    av.setModal(true);
    av.exec();
}

void MainWindow::on_pushButton_22_clicked()
{
    suppv sv;
    sv.setModal(true);
    sv.exec();
}




void MainWindow::on_pushButton_10_clicked()
{
    affl a;
    a.setModal(true);
    a.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    suppl sl;
    sl.setModal(true);
    sl.exec();
}
