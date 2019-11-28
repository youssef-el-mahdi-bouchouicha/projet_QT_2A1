#include "bus.h"
#include "ui_bus.h"
#include<QMessageBox>
#include "g_bus.h"
#include<QSystemTrayIcon>
#include<QComboBox>
#include"stati.h"
bus::bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bus)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

bus::~bus()
{
    delete ui;
}

void bus::on_pushButton_9_clicked()
{
//QString type_,QString dispo_,QString kilo_,QString date_e_)

    int id = ui->lineEdit_4->text().toInt();
    QString mat= ui->lineEdit->text();
    QString etat_= ui->comboBox->currentText();
     QString date_a= ui->dateEdit->text();
      QString marque_= ui->lineEdit_2->text();
         QString type_= ui->lineEdit_6->text();
            QString dispo_= ui->lineEdit_7->text();
               QString kilo_= ui->lineEdit_8->text();
                  QString date_e_= ui->dateEdit_2->text();
  G_BUS e(id,mat,etat_,date_a,marque_,type_,dispo_,kilo_,date_e_);
  bool test=e.ajouter();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void bus::on_pushButton_11_clicked()
{
    stati s;
    s.exec();
}
