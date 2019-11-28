#include "rtransp.h"
#include "ui_rtransp.h"
#include "restr.h"
#include<QMessageBox>
#include<QDebug>
#include<QtWidgets>
#include<QSystemTrayIcon>

rtransp::rtransp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rtransp)
{
    ui->setupUi(this);
}

rtransp::~rtransp()
{
    delete ui;
}



void rtransp::on_pushButton_3_clicked()
{
    int res = ui->res->text().toInt();
    int idc = ui->idc->text().toInt();
    int idr = ui->idr->text().toInt();
    QString etp= ui->etp->text();
    QString dat= ui->dat->text();
    QString dest= ui->dest->text();
    QString type= ui->type->text();

  restr e(idr,dat,dest,idc,type,etp,res);
  bool test=e.ajouter();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
