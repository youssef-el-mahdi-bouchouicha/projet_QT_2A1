#include "affl.h"
#include "ui_affl.h"
#include<QString>
#include<string>
affl::affl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affl)
{
    ui->setupUi(this);
    ui->tablereserl->setModel(tmpreslog.afficher()) ;
}

affl::~affl()
{
    delete ui;
}

void affl::on_recher1_clicked()
{

   QString res=ui->recher_2->text();

    ui->tablereserl->setModel(tmpreslog.rechercher(res));
}

void affl::on_pushButton_17_clicked()
{

    ui->tablereserl->setModel(tmpreslog.tri());
}

void affl::on_recher_2_textEdited(const QString &arg1)
{

    ui->tablereserl->setModel(tmpreslog.rechav(arg1));
}
