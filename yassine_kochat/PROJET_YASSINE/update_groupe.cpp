#include "update_groupe.h"
#include "ui_update_groupe.h"
#include "groupe.h"
#include <QMessageBox>

update_groupe::update_groupe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_groupe)
{
    ui->setupUi(this);
}

update_groupe::~update_groupe()
{
    delete ui;
}

void update_groupe::on_pushButton_18_clicked()
{
    QString type= ui->lineEdit_type->text();

    int nombre=ui->lineEdit_nbr->text().toInt();
    int id_personnel=ui->lineEdit_id_p->text().toInt();
    int id=ui->lineEdit_id->text().toInt();
  groupe g(type,id_personnel,nombre,id);
  bool test=g.update();
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
