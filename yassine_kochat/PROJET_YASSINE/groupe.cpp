#include "groupe.h"
#include <QDebug>
groupe::groupe()
{

id=0;
type="";
nombre=0;
id_personnel=0;
}
groupe::groupe(QString type,int id_personnel,int nombre,int id)
{

 this->type=type;

    this->id_personnel=id_personnel;
    this->nombre=nombre;
    this->id=id;
}
QString groupe::get_type(){return  type;}


int groupe::get_nombre(){return  nombre;}
int groupe::get_idpersonnel(){return  id_personnel;}
int groupe::get_id(){return  id;}
bool groupe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO GROUPE_CLIENT (TYPE,ID_PERS,NBRE_VOYAGEURS,ID) "
                    "VALUES (:type,:id_personnel, :nombre,:id)");

query.bindValue(":type", type);
query.bindValue(":nombre", nombre);
query.bindValue(":id_personnel", id_personnel);
query.bindValue(":id",res);


return    query.exec();
}
QSqlQueryModel * groupe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from GROUPE_CLIENT");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type "));

model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_PERSONNEL"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));



    return model;
}
bool groupe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from GROUPE_CLIENT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool groupe ::update()
{
QSqlQuery query;
  int first=0 ;
       QString res= QString::number(id_personnel);
      QString res1=QString::number(id);
      QString res3=QString::number(nombre);
        QString editer ="Update GROUPE_CLIENT set" ;
      query.bindValue(":type",type);
      if(type!="")
      {
          editer+=" TYPE = :type" ;
          first=1 ;
      }

      query.bindValue(":id_personnel",id_personnel);
      if(res!=""&& first!=0)
          editer+=" ,ID_PERS= :id_personnel" ;
      else if (res!=""&&first==0)
        {
          editer+=" ID_PERS= :id_perssonel" ;
          first=1 ;
        }
           query.bindValue(":nombre",nombre);
           if(res3!=""&& first!=0)
               editer+=" ,NBRE_VOYAGEURS= :nombre" ;
           else if (res3!="" && first==0)
           {
              editer+=" NBRE_VOYAGEURS = :nombre" ;
              first=1 ;
           }



             editer+=" where ID = :id" ;



             QByteArray chaine = editer.toLocal8Bit();
             const char *final = chaine.data();


          query.prepare(final);


          query.bindValue(":id",QVariant(res1).toInt());

          query.bindValue(":type", type);
          query.bindValue(":nombre", nombre);
          query.bindValue(":id_personnel", id_personnel);

       return query.exec();
}
