#include "supprimer_client.h"
#include "ui_supprimer_client.h"
#include <QMessageBox>

supprimer_client::supprimer_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_client)
{
    ui->setupUi(this);
}

supprimer_client::~supprimer_client()
{
    delete ui;
}

void supprimer_client::on_pushButton_9_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=tmpclients.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
