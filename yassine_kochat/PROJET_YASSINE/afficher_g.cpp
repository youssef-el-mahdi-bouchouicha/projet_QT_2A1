#include "afficher_g.h"
#include "ui_afficher_g.h"

afficher_g::afficher_g(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_g)
{
    ui->setupUi(this);
     ui->tableView->setModel(tmpgroupe.afficher());
}

afficher_g::~afficher_g()
{
    delete ui;
}
