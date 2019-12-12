#include "supprimer.h"
#include "ui_supprimer.h"
#include <QMessageBox>
#include"contact_hebergement_transport.h"
supprimer::supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);
}

supprimer::~supprimer()
{
    delete ui;
}

void supprimer::on_pushButton_2_clicked()
{
    int  ID_HT= ui->lineEdit->text().toInt();
       bool test=a.supprimer(ID_HT);
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
