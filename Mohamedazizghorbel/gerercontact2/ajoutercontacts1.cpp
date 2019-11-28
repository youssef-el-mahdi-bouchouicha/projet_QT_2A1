#include "ajoutercontacts1.h"
#include "ui_ajoutercontacts1.h"
#include<QMessageBox>
#include"contact_autres.h"
#include<QSystemTrayIcon>
ajoutercontacts1::ajoutercontacts1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutercontacts1)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
}

ajoutercontacts1::~ajoutercontacts1()
{
    delete ui;
}

void ajoutercontacts1::on_pushButton_clicked()
{

    int ID_RESP = ui->lineEdit->text().toInt();
QString NOM_RESP= ui->lineEdit_2->text();
QString PRENOM_RESP=ui->lineEdit_3->text();
QString OCCUPATION = ui->lineEdit_4->text();
QString TYPE = ui->lineEdit_5->text();
QString ADDRESSE =ui->lineEdit_6->text();
QString E_MAIL = ui->lineEdit_7->text();
int GSM = ui->lineEdit_8->text().toInt();
CONTACT_AUTRES o (ID_RESP,NOM_RESP,PRENOM_RESP,OCCUPATION,TYPE,ADDRESSE,E_MAIL,GSM);
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
