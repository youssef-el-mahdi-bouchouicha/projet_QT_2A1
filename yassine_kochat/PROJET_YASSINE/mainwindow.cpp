#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "ajout_g.h"
#include "affichage.h"
#include"supprimer_client.h"
#include "supprimer_g.h"
#include "afficher_g.h"
#include "update_client.h"
#include "update_groupe.h"
#include "stati.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Ajout A;


    A.setWindowTitle("ajout");
    A.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Ajout_G A;
    A.setWindowTitle("ajout_g");
    A.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Affichage A;
    A.setWindowTitle("affichage");
    A.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    supprimer_client s;

    s.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    supprimer_g s;
    s.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    afficher_g a;
    a.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    update_client u;
    u.exec();

}

void MainWindow::on_pushButton_6_clicked()
{
   update_groupe g;
   g.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    stati s;
    s.exec();
}
