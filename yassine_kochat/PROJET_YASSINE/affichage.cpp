#include "affichage.h"
#include "ui_affichage.h"
#include <QMessageBox>

Affichage::Affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affichage)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpclient.afficher());
}

Affichage::~Affichage()
{
    delete ui;
}

void Affichage::on_pushButton_18_clicked()
{
    int id = ui->lineEdit->text().toInt();

bool test=true;
if(test==(true))
{

ui->tableView->setModel(tmpclient.chercher(id));
QMessageBox::information(nullptr, QObject::tr("chercher un client"),
                  QObject::tr("client existe.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

}


void Affichage::on_pushButton_19_clicked()
{
    ui->tableView->setModel(tmpclient.afficher_tri_par_id());

}
