#include "affiche1.h"
#include "ui_affiche1.h"
#include"contact_autres.h"

affiche1::affiche1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affiche1)
{
    ui->setupUi(this);
   ui->tableView->setModel(a.afficher());
}

affiche1::~affiche1()
{
    delete ui;
}

void affiche1::on_pushButton_2_clicked()
{
    /*int refrayon = ui->chercher_contact->text().toInt();
    ui->tableView->setModel(a.chercher_contact(refrayon));*/
    QString res =ui->chercher_contact->text();
    ui->tableView->setModel(a.checher_avance(res));
}

void affiche1::on_pushButton_3_clicked()
{
    ui->tableView->setModel(a.afficher1_trier());
}
