#include "affiche.h"
#include "ui_affiche.h"
#include"contact_hebergement_transport.h"

affiche::affiche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affiche)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
}

affiche::~affiche()
{
    delete ui;
}

void affiche::on_pushButton_clicked()
{
    int refrayon = ui->line_chercher_cont_h->text().toInt();
    ui->tableView->setModel(e.chercher_contact_heb_trans(refrayon));
}

void affiche::on_pushButton_2_clicked()
{
     ui->tableView->setModel(e.afficher_trier());
}
