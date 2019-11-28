#include "supprimer_v.h"
#include "ui_supprimer_v.h"
#include"voitures_p.h"
#include <QMessageBox>
supprimer_v::supprimer_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_v)
{
    ui->setupUi(this);
}

supprimer_v::~supprimer_v()
{
    delete ui;
}

void supprimer_v::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=v.supprimer(id);
    if(test)
    {//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
