#include "modifier_v.h"
#include "ui_modifier_v.h"
#include "voitures_p.h"
#include <QMessageBox>

modifier_v::modifier_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_v)
{
    ui->setupUi(this);
}

modifier_v::~modifier_v()
{
    delete ui;
}

void modifier_v::on_pushButton_9_clicked()
{
    int id = ui->lineEdit_6->text().toInt();
    QString mat= ui->lineEdit->text();
    QString etat_= ui->lineEdit_2->text();
     QString date_a= ui->lineEdit_3->text();
      QString marque_= ui->lineEdit_4->text();
  VOITURES_P P(id,mat,etat_,date_a,marque_);
  bool test=P.update();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
