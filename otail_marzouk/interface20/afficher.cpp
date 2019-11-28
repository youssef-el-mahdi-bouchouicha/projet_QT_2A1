#include "afficher.h"
#include "ui_afficher.h"
#include "g_bus.h"

afficher::afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher)
{
    ui->setupUi(this);
    ui->tableView->setModel(a.afficher());
}

afficher::~afficher()
{
    delete ui;
}

void afficher::on_pushButton_10_clicked()
{
    QString res= ui->lineEdit->text();

     ui->tableView->setModel(a.chercher(res));
}

void afficher::on_pushButton_11_clicked()
{
ui->tableView->setModel(a.trier());
}

void afficher::on_pushButton_clicked()
{
     ui->tableView->setModel(a.afficher());
}
