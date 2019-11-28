#include "annonces.h"
#include <QDebug>
Annonces::Annonces()
{
    id_voyage=0;
    type="";
    destination="";
    date_dep="";
    date_retour="";
    id_bus="";
    description="";
}
Annonces::Annonces(int id,QString type,QString destination,QString  date_dept,QString date_retour,QString id_bus,QString description )
{
  this->id_voyage=id;
    this->type=type;
    this->destination=destination;
    this->date_dep=date_dept;
    this->date_retour=date_retour;
    this->id_bus=id_bus;
    this->description=description;

}
bool Annonces::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_voyage);
Annonces an;
if(an.rech_voy(id_voyage)==0)
{
query.prepare("INSERT INTO ANNONCE_VOYAGE (ID_VOYAGE,TYPE,DESTINATION,DATE_DEPART,DATE_RETOUR,ID_BUS,DESCRIPTION) "
                    "VALUES (:id_voyage,:type,:destination,:date_dep,:date_retour,:id_bus,:description)");
query.bindValue(":id_voyage", res);
query.bindValue(":type",type);
query.bindValue(":destination",destination);
query.bindValue(":date_dep",date_dep);
query.bindValue(":date_retour",date_retour);
query.bindValue(":id_bus",id_bus);
query.bindValue(":description",description);
}

return    query.exec();
}


QSqlQueryModel * Annonces::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_VOYAGE  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOYAGE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_BUS"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}
bool Annonces::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ANNONCE_VOYAGE where ID_VOYAGE = :id_voyage ");
query.bindValue(":id_voyage", res);
return    query.exec();
}

QSqlQueryModel * Annonces::afficher_voy_trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_VOYAGE order by ID_VOYAGE asc  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOYAGE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_BUS"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}

QSqlQueryModel * Annonces::chercher_voyage(int id_voy)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from ANNONCE_VOYAGE WHERE ID_VOYAGE=:id_voy"));

     query.bindValue(":id_voy",id_voy);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VOYAGE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEPART"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_BUS"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));


return model;
 }

int Annonces::rech_voy(int x)
{
   /* QSqlQuery query;
       query.prepare("select * from ANNONCE_VOYAGE where ID_VOYAGE = :id_voyage");
       query.bindValue(":id_voyage", x);
       return query.exec();*/

     QSqlQuery query;
     int count =0;
     bool test =0;
     QString idb= QString :: number(x);
     if(query.exec("select ID_VOYAGE from ANNONCE_VOYAGE where ID_VOYAGE='"+idb+"'"))
     {
         while(query.next())
                   count++;
               if(count>=1)
                   test=1;

     }
    return test;

}

bool Annonces::modifier_voy(int id,QString type,QString destination,QString  date_dept,QString date_retour,QString id_bus,QString description )
{
QSqlQuery query;


    query.prepare("update ANNONCE_VOYAGE set TYPE=:type,DESTINATION=:destination,DATE_DEPART=:date_dept,DATE_RETOUR=:date_retour,ID_BUS=:id_bus,DESCRIPTION=:description where ID_VOYAGE=:id_voyage");
    query.bindValue(":id_voyage", id);
    query.bindValue(":type", type);
    query.bindValue(":destination", destination);
    query.bindValue(":date_dept", date_dept);
    query.bindValue(":date_retour", date_retour);
    query.bindValue(":id_bus", id_bus);
    query.bindValue(":description", description);


    return query.exec();
}
