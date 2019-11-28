#include "ajout_g.h"
#include "ui_ajout_g.h"
#include "QMessageBox"
#include "groupe.h"

Ajout_G::Ajout_G(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout_G)
{
    ui->setupUi(this);
}


Ajout_G::~Ajout_G()
{
    delete ui;
}

void Ajout_G::on_pushButton_9_clicked()
{

    QString type= ui->comboBox->currentText();

    int nombre=ui->lineEdit_nbr->text().toInt();
    int id_personnel=ui->lineEdit_id_p->text().toInt();
    int id=ui->lineEdit_id->text().toInt();
  groupe g(type,id_personnel,nombre,id);
  bool test=g.ajouter();
  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un groupe de client"),
                  QObject::tr("groupe de client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("ajouter un groupe de client "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
