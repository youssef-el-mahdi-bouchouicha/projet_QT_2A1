#include "suppv.h"
#include "ui_suppv.h"
#include "resvoy.h"
#include <QMessageBox>
#include "modifv.h"

suppv::suppv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::suppv)
{
    ui->setupUi(this);
}

suppv::~suppv()
{
    delete ui;
}

void suppv::on_pushButton_2_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=tmpresvoy.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void suppv::on_pushButton_3_clicked()
{
    modifv mv;
    mv.setModal(true);
    mv.exec();
}
