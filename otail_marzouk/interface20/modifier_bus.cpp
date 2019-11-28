#include "modifier_bus.h"
#include "ui_modifier_bus.h"
#include"g_bus.h"
#include"QMessageBox"

modifier_bus::modifier_bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_bus)
{
    ui->setupUi(this);
}

modifier_bus::~modifier_bus()
{
    delete ui;
}

void modifier_bus::on_pushButton_9_clicked()
{
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
  bool test=e.update();
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
