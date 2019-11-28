#include "ajoutercontacts.h"
#include "ui_ajoutercontacts.h"
#include<QMessageBox>
#include"contact_hebergement_transport.h"
#include<QSystemTrayIcon>
#include"stati.h"
#include<QDebug>
Ajoutercontacts::Ajoutercontacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajoutercontacts)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

Ajoutercontacts::~Ajoutercontacts()
{
    delete ui;
}

void Ajoutercontacts::on_pushButton_clicked()
{
    int ID_HT = ui->lineEdit->text().toInt();
    QString TYPE= ui->comboBox->currentText();
    int GSM= ui->lineEdit_3->text().toInt();
     QString FAX= ui->lineEdit_4->text();
      QString E_MAIL= ui->lineEdit_5->text();
  QString ADRESSE=ui->lineEdit_6->text();

    CONTACT_HEBERGEMENT_TRANSPORT o(ID_HT,TYPE,GSM,FAX,E_MAIL ,ADRESSE);

bool test= o.ajouter();
if(test)
{
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


void Ajoutercontacts::on_pushButton_3_clicked()
{
    stati s;
    s.exec();
}
