#include "afficher_v.h"
#include "ui_afficher_v.h"
#include"voitures_p.h"

afficher_v::afficher_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_v)
{
    ui->setupUi(this);
    ui->ooo->setModel(p.afficher());

}

afficher_v::~afficher_v()
{
    delete ui;
}

void afficher_v::on_pushButton_clicked()
{
    ui->ooo->setModel(p.trier());
}

void afficher_v::on_pushButton_2_clicked()
{
     QString res= ui->lineEdit->text();
      ui->ooo->setModel(p.chercher(res));

}

void afficher_v::on_lineEdit_textEdited(const QString &arg1)
{
if (arg1=="")
{
    ui->ooo->setModel(p.afficher());
}
else
     ui->ooo->setModel(p.chercher(arg1));

}
