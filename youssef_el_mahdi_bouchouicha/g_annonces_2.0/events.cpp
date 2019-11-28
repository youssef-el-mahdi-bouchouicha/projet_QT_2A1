#include "events.h"
#include <QDebug>
Events::Events()
{
id_event=0;
nbre_jour=0;
prix=0;
type_voyageurs="";
description="";
}

Events::Events(int id,int nbre_jour,QString type_voyageurs,int prix,QString descr)
{
    this->id_event=id;
    this->nbre_jour=nbre_jour;
    this->type_voyageurs=type_voyageurs;
    this->prix=prix;
    this->description=descr;


}


int Events::rech_event(int x)
{
    QSqlQuery query;
     int count =0;
     bool test =0;
     QString idb= QString :: number(x);
     if(query.exec("select ID_EVENT from ANNONCE_EVENTS where ID_EVENT='"+idb+"'"))
     {
         while(query.next())
                   count++;
               if(count>=1)
                   test=1;

     }
    return test;

}


bool Events::ajouter_event()
{
QSqlQuery query;
QString res= QString::number(id_event);
QString res2= QString::number(nbre_jour);
QString res3= QString::number(prix);
Events ev;
if(ev.rech_event(id_event)==0)
{
query.prepare("INSERT INTO ANNONCE_EVENTS (ID_EVENT,NBRE_JOURS,TYPE_VOYAGEURS,PRIX,DESCRIPTION) "
                    "VALUES (:id_event,:nbre_jour,:type_voyageurs,:prix,:description)");
query.bindValue(":id_event", res);
query.bindValue(":nbre_jour",res2);
query.bindValue(":type_voyageurs",type_voyageurs);
query.bindValue(":prix",res3);
query.bindValue(":description",description);
}
return    query.exec();
}

QSqlQueryModel * Events::afficher_event()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_EVENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_JOURS"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}


bool Events::supprimer_event(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ANNONCE_EVENTS where ID_EVENT = :id_event ");
query.bindValue(":id_event", res);
return    query.exec();
}
QSqlQueryModel * Events::afficher_event_trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANNONCE_EVENTS order by ID_EVENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_JOURS"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model;
}

QSqlQueryModel * Events::chercher_event(int id_event)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from ANNONCE_EVENTS WHERE ID_EVENT=:id_event"));

     query.bindValue(":id_event",id_event);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_JOURS"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_VOYAGEURS"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));


return model;
 }
