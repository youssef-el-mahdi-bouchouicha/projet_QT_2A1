#include "modifv.h"
#include "ui_modifv.h"
#include "resvoy.h"
#include<QMessageBox>
#include<QDebug>
#include<QtWidgets>
#include<QSystemTrayIcon>

modifv::modifv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifv)
{
    ui->setupUi(this);
}

modifv::~modifv()
{
    delete ui;
}

void modifv::on_pushButton_3_clicked()
{

    int res = ui->lineEdit_res->text().toInt();
    int idv =ui->lineEdit_idv->text().toInt();
    int idc = ui->lineEdit_idc->text().toInt();
    int idr = ui->lineEdit_idr->text().toInt();
    QString etp= ui->comboBox->currentText();

  resvoy e(idr,idc,idv,res,etp);
  bool test=e.modifier();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
