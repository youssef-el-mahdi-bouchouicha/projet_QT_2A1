#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"bus.h"
#include"vp.h"
#include"afficher.h"
#include "suppr.h"
#include"supprimer_v.h"
#include"afficher_v.h"
#include"modifier_v.h"
#include"modifier_bus.h"
#include"chercher_bus.h"
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
{  //this->hide();
    bus b;
    b.exec();

}

void MainWindow::on_pushButton_5_clicked()
{
    vp v;
    v.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
   afficher a;


   a.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    suppr s;
    s.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    supprimer_v v;
    v.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
afficher_v a;
a.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    modifier_v v;
        v.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    modifier_bus m;
    m.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    chercher_bus b;
    b.exec();
}
