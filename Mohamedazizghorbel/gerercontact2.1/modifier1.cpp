#include "modifier1.h"
#include "ui_modifier1.h"
#include"contact_autres.h"
#include<QMessageBox>
modifier1::modifier1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier1)
{
    ui->setupUi(this);
}

modifier1::~modifier1()
{
    delete ui;
}

void modifier1::on_pushButton_clicked()
{
    int ID_RESP=ui->lineEdit->text().toInt();
    QString NOM_RESP=ui->lineEdit_2->text();
    QString PRENOM_RESP=ui->lineEdit_3->text();
    QString OCCUPATION=ui->lineEdit_4->text();
    QString TYPE=ui->lineEdit_5->text();
    QString ADDRESSE=ui->lineEdit_6->text();
    QString E_MAIL=ui->lineEdit_7->text();
    int GSM=ui->lineEdit_8->text().toInt();
    CONTACT_AUTRES o (ID_RESP,NOM_RESP,PRENOM_RESP,OCCUPATION,TYPE,ADDRESSE,E_MAIL,GSM);
    bool test =o.modifiercontact();
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
