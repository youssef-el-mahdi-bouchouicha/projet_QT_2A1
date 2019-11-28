#include "suppr.h"
#include "ui_suppr.h"
#include <QMessageBox>
#include"g_bus.h"

suppr::suppr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::suppr)
{
    ui->setupUi(this);
}

suppr::~suppr()
{
    delete ui;
}

void suppr::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=a.supprimer(id);
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
