#include "supprimer1.h"
#include "ui_supprimer1.h"
#include <QMessageBox>
#include"contact_autres.h"
supprimer1::supprimer1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer1)
{
    ui->setupUi(this);
}

supprimer1::~supprimer1()
{
    delete ui;
}

void supprimer1::on_pushButton_clicked()
{
    int  ID_RESP= ui->lineEdit->text().toInt();
       bool test =a.supprimer(ID_RESP);
       if(test)
       {ui->tableView->setModel(a.afficher());
           QMessageBox::information(nullptr, QObject::tr("Supprimer contact"),
                       QObject::tr("contact supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer contact"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
