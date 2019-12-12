#include "modifier.h"
#include "ui_modifier.h"
#include"contact_hebergement_transport.h"
#include<QMessageBox>
modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_pushButton_clicked()
{ int ID_HT = ui->lineEdit->text().toInt();
    QString TYPE= ui->comboBox->currentText();
    int GSM= ui->lineEdit_3->text().toInt();
     QString FAX= ui->lineEdit_4->text();
      QString E_MAIL= ui->lineEdit_5->text();
  QString ADRESSE=ui->lineEdit_5->text();

    CONTACT_HEBERGEMENT_TRANSPORT o(ID_HT,TYPE,GSM,FAX,E_MAIL ,ADRESSE);

bool test= o.modifiercontact();
if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un contact"),
                QObject::tr("contact modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un contact"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


