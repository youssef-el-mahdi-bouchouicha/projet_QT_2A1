#include "personnel.h"
#include <QString>
#include <QDebug>

personnel::personnel()
{
    id=0;
    nom="";
    prenom="";
}
personnel::personnel(int id_,QString nom_,QString prenom_,QString gsm_)
{
    id=id_;
    nom=nom_;
    prenom=prenom_;
    gsm=gsm_;
}
QString personnel::get_nom(){return  nom;}
QString personnel::get_prenom(){return prenom;}
int personnel::get_id(){return  id;}
QString personnel::get_gsm(){return gsm;}
bool personnel::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PERSONNELS (ID_PERS, NOM_PERS, PRENOM_PERS,GSM) "
                    "VALUES (:id, :nom, :prenom,:gsm)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":gsm", gsm);

return    query.exec();
}
QSqlQueryModel * personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNELS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PERS "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PERS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));

    return model;
}
bool personnel::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PERSONNELS where ID_PERS = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * personnel::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNELS order by ID_PERS asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PERS "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PERS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));

    return model;
}
QSqlQueryModel * personnel::chercher(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
       // QString res= ui->lineEdit->text();
        model->setQuery("select * from PERSONNELS where ID_PERS='"+res+"' ");//='"+res+"'
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PERS "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PERS"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
        return model;
}
bool personnel::update()
{
    QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(id);
             QString editer="Update PERSONNELS set" ;
            query.bindValue(":nom",nom);
            if(nom!="")
            {
                editer+=" NOM_PERS = :nom" ;
                first=1 ;
            }

            query.bindValue(":pernom",prenom);
            if(prenom!=""&& first!=0)
                editer+=" ,PRENOM_PERS= :prenom" ;
            else if (prenom!=""&&first==0)
              {
                editer+=" PRENOM_PERS= :prenom" ;
                first=1 ;
              }
                 query.bindValue(":gsm",gsm);
                 if(gsm!=""&& first!=0)
                     editer+=" ,GSM = :gsm" ;
                 else if (gsm!="" && first==0)
                 {
                    editer+=" GSM = :gsm" ;
                    first=1 ;
                 }




                  /* query.bindValue(":kilometrage",kilometrage);
                   if(kilometrage!=""&& first!=0)
                       editer+=" ,KILOMETRAGE = :kilometrage" ;
                   else if (kilometrage!=""&&first==0)
                   {
                     editer+=" KILOMETRAGE = :kilometrage" ;
                     first=1 ;
                   }*/





                   editer+=" where ID_PERS = :id" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();

                 /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                               QObject::tr(final
                                           ), QMessageBox::Cancel); */

               query.prepare(final);

                   //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

             query.bindValue(":id",QVariant(res1).toInt());
             query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
                 query.bindValue(":gsm",gsm);


             return query.exec();
}
