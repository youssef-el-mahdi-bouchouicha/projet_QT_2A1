#include "vp.h"
#include "ui_vp.h"
#include<QMessageBox>
#include"voitures_p.h"
#include<QSystemTrayIcon>
vp::vp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vp)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

vp::~vp()
{
    delete ui;
}

void vp::on_pushButton_9_clicked()
{
    int id = ui->lineEdit_6->text().toInt();
    QString mat= ui->lineEdit->text();
    QString etat_= ui->lineEdit_2->text();
     QString date_a= ui->lineEdit_3->text();
      QString marque_= ui->lineEdit_4->text();
  VOITURES_P e(id,mat,etat_,date_a,marque_);
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


