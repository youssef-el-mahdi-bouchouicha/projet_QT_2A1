#include "supprimer_g.h"
#include "ui_supprimer_g.h"
#include <QMessageBox>

supprimer_g::supprimer_g(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_g)
{
    ui->setupUi(this);
}

supprimer_g::~supprimer_g()
{
    delete ui;
}

void supprimer_g::on_pushButton_9_clicked()
{
    int id_personnel= ui->lineEdit->text().toInt();
    bool test=tmpgroupe.supprimer(id_personnel);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un groupe de client"),
                    QObject::tr("groupe de client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un groupe de client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
