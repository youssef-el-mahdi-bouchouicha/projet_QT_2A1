#include "client.h"
#include <QDebug>
client::client()
{
id=0;
nom="";
prenom="";
mail="";
adresse="";
date="";
tel=0;
age=0;
}
client::client(int id,QString nom,QString prenom,int tel,QString mail,QString adresse,QString date,int age)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->tel=tel;
    this->mail=mail;
    this->adresse=adresse;
    this->date=date;
    this->age=age;

}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
QString client::get_mail(){return  mail;}
QString client::get_adresse(){return adresse;}
QString client::get_date(){return date;}
int client::get_id(){return  id;}

int client::get_tel(){return  tel;}
int client::get_age(){return age;}
bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(tel);
client c;
if (c.rech(id)==0)
{
query.prepare("INSERT INTO CLIENTS (ID_CLIENT, NOM, PRENOM,GSM,E_MAIL,ADRESS,DATE_NAISSANCE,AGE) "
                    "VALUES (:id, :nom, :prenom,:tel,:mail,:adresse,:date,:age)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":tel", res1);
query.bindValue(":mail", mail);
query.bindValue(":adresse", adresse);
query.bindValue(":date", date);
query.bindValue(":age", age);
}
return    query.exec();
}
QSqlQueryModel *client::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTS  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));

    return model;

}
QSqlQueryModel *client::afficher_tri_par_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTS order by ID_CLIENT asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));

    return model;

}
bool client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CLIENTS where ID_CLIENT = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool client::update()
{

      QSqlQuery query;
        int first=0 ;
             QString res= QString::number(tel);
            QString res1=QString::number(id);
            QString res2=QString::number(age);


              QString editer ="Update CLIENTS set" ;
            query.bindValue(":nom",nom);
            if(nom!="")
            {
                editer+=" NOM = :nom" ;
                first=1 ;
            }

            query.bindValue(":prenom",prenom);
            if(prenom!=""&& first!=0)
                editer+=" ,PRENOM= :prenom" ;
            else if (prenom!=""&&first==0)
              {
                editer+=" PRENOM= :prenom" ;
                first=1 ;
              }
                 query.bindValue(":tel",tel);
                 if(res!=""&& first!=0)
                     editer+=" ,GSM= :tel" ;
                 else if (res!="" && first==0)
                 {
                    editer+=" GSM = :tel" ;
                    first=1 ;
                 }

                   query.bindValue(":mail",mail);
                   if(mail!=""&& first!=0)
                       editer+=" ,E_MAIL = :mail" ;
                   else if (mail!=""&&first==0)
                   {
                     editer+=" E_MAIL = :mail" ;
                     first=1 ;
                   }
                   query.bindValue(":adresse",adresse);
                   if(adresse!=""&& first!=0)
                       editer+=" ,ADRESS = :adresse" ;
                   else if (adresse!=""&&first==0)
                   {
                     editer+=" ADRESS= :adresse"  ;
                     first=1 ;
                   }

                   query.bindValue(":date",date);
                   if(date!=""&& first!=0)
                       editer+=" ,DATE_NAISSANCE = :date" ;
                   else if (date!=""&&first==0)
                   {
                     editer+=" DATE_NAISSANCE= :date" ;
                     first=1 ;
                   }
                   query.bindValue(":age",age);
                   if(res2!=""&& first!=0)
                       editer+=" ,AGE = :res2" ;
                   else if (date!=""&&first==0)
                   {
                     editer+=" AGE= :res2" ;
                     first=1 ;
                   }
                   editer+=" where ID_CLIENT = :id" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


                query.bindValue(":id",QVariant(res1).toInt());
             query.bindValue(":nom",nom);
                query.bindValue(":prenom",prenom);
                 query.bindValue(":tel",res);
                   query.bindValue(":mail",mail);
                   query.bindValue(":adresse",adresse);
                   query.bindValue(":date",date);
                   query.bindValue(":age",res2);



             return query.exec();
}
QSqlQueryModel * client::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from CLIENTS WHERE ID_CLIENT=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));



return model;
 }

int client ::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID from CLIENTS where  ID='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}
