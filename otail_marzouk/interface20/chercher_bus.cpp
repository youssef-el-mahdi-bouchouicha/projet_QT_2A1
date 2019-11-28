#include "chercher_bus.h"
#include "ui_chercher_bus.h"
#include "QSqlQueryModel"
#include"g_bus.h"


chercher_bus::chercher_bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chercher_bus)
{
    ui->setupUi(this);
}

chercher_bus::~chercher_bus()
{
    delete ui;
}

void chercher_bus::on_pushButton_clicked()
{
    QString res= ui->lineEdit->text();
  /*  QSqlQueryModel * model= new QSqlQueryModel();
    QString res= ui->lineEdit->text();
    model->setQuery("select * from BUS where ID_BUS='"+res+"' ");//='"+res+"'
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_BUS"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_DERNIER_ENTRETIENT"));
    ui->tableView->setModel(model);*/
     ui->tableView->setModel(a.chercher(res));
}
