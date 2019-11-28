#include "update_client.h"
#include "ui_update_client.h"
#include "client.h"
#include <QMessageBox>

update_client::update_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_client)
{
    ui->setupUi(this);
}

update_client::~update_client()
{
    delete ui;
}

void update_client::on_pushButton_9_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail=ui->lineEdit_mail->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString date=ui->lineEdit_date->text();
    int tel=ui->lineEdit_tel->text().toInt();
    int age=ui->lineEdit_age->text().toInt();
  client c(id,nom,prenom,tel,mail,adresse,date,age);
  bool test=c.update();

  if(test)
{


QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("client modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



