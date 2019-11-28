#include "rlog.h"
#include "ui_rlog.h"
#include"QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"reslog.h"


Rlog::Rlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rlog)
{
    ui->setupUi(this);
}

Rlog::~Rlog()
{
    delete ui;
}

void Rlog::on_pushButton_3_clicked()
{

    int idr = ui->idr->text().toInt();
    int idc =ui->idc->text().toInt();
    int nbr = ui->nbr->text().toInt();
    QString dat = ui->dat->text();
    int idco=ui->idco->text().toInt();
    QString etp= ui->etp->currentText();
    int res=ui->res->text().toInt();

  reslog e(idr,idc,nbr,dat,idco,etp,res);
  bool test=e.ajouter();
  if(test)
{
    //  mysystem->showMessage(tr("notification"),tr("ajout avec success"));
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
