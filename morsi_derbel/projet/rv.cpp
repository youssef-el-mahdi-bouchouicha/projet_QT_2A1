#include "rv.h"
#include "ui_rv.h"
#include "ui_affv.h"
#include "affv.h"
#include"resvoy.h"
#include<QMessageBox>
#include<QDebug>
#include<QtWidgets>
#include<QSystemTrayIcon>
#include"stati.h"

rv::rv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rv)
{
    ui->setupUi(this);
    mysystem= new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

rv::~rv()
{
    delete ui;
}

void rv::on_pushButton_3_clicked()
{
   // Ui_affv af;

    int res = ui->lineEdit_res->text().toInt();
    int idv =ui->lineEdit_idv->text().toInt();
    int idc = ui->lineEdit_idc->text().toInt();
    int idr = ui->lineEdit_idr->text().toInt();
    QString etp= ui->comboBox->currentText();

  resvoy e(idr,idc,idv,res,etp);
  bool test=e.ajouter();
  if(test)
{
      mysystem->showMessage(tr("notification"),tr("ajout avec success"));
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}




