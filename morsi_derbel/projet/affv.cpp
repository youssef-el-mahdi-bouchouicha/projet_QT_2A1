#include "affv.h"
#include "ui_affv.h"
#include "resvoy.h"
#include"stati.h"


affv::affv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affv)
{
    ui->setupUi(this);
    ui->tablereserv->setModel(tmpresvoy.afficher()) ;
}


affv::~affv()
{
    delete ui;
}


void affv::on_pushButton_2_clicked()
{

   QString res=ui->recher->text();

    ui->tablereserv->setModel(tmpresvoy.rechercher(res));
}

void affv::on_pushButton_3_clicked()
{

    ui->tablereserv->setModel(tmpresvoy.tri());


}

void affv::on_pushButton_5_clicked()
{
    stati s;
  s.exec();
}

void affv::on_recher_textEdited(const QString &arg1)
{

    ui->tablereserv->setModel(tmpresvoy.rechav(arg1));


}
