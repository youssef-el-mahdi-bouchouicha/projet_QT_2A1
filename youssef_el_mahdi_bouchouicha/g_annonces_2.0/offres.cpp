#include "offres.h"
#include <QDebug>

Offres::Offres()
{
    id_offre=0;
    periode="";
    type_voyageurs="";
    date_dep="";
    date_retour="";
    description="";
}
Offres::Offres(int id,QString periode,QString type_voyageurs,QString  date_dept,QString date_retour,QString descr )
{
    this->id_offre=id;
    this->periode=periode;
    this->type_voyageurs=type_voyageurs;
    this->date_dep=date_dept;
    this->date_retour=date_retour;
    this->description=descr;

}

int Offres::rech_offre(int x)
{
    QSqlQuery query;
     int count =0;
     bool test =0;
     QString idb= QString :: number(x);
     if(query.exec("select ID_OFFRE from ANNONCE_OFFRE where ID_OFFRE='"+idb+"'"))
     {
         while(query.next())
                   count++;
               if(count>=1)
                   test=1;

     }
    return test;

}

bool Offres::ajouter_offres()
{
QSqlQuery query;
QString res= QString::number(id_offre);
Offres off;
if(off.rech_offre(id_offre)==0)
{
query.prepare("INSERT INTO ANNONCE_OFFRE (ID_OFFRE,PERIODE,TYPE_VOYAGEURS,DATE_DEPART,DATE_RETOUR,DESCRIPTION) "
                    "VALUES (:id_offre,:periode,:type_voyageurs,:date_dep,:date_retour,:description)");
query.bindValue(":id_offre", res);
query.bindValue(":periode",periode);
query.bindValue(":destination",type_voyageurs);
query.bindValue(":date_dep",date_dep);
query.bindValue(":date_retour",date_retour);
query.bindValue(":description",description);
}
return    query.exec();
}

QSqlQueryModel * Offres::afficher_offres()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_OFFRE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OFFRE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERIODE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}


bool Offres::supprimer_offres(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ANNONCE_OFFRE where ID_OFFRE = :id_offre ");
query.bindValue(":id_offre", res);
return    query.exec();
}

QSqlQueryModel * Offres::afficher_offre_trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_OFFRE order by ID_OFFRE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OFFRE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERIODE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}


QSqlQueryModel * Offres::chercher_offre(int id_offre)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from ANNONCE_OFFRE WHERE ID_OFFRE=:id_offre"));

     query.bindValue(":id_offre",id_offre);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OFFRE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERIODE "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));

      query.exec();
     model->setQuery(query);



return model;
 }
