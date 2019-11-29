#include "etatpers.h"
#include <QString>
#include <QDebug>

etatpers::etatpers()
{

}
etatpers::etatpers(int id_,QString nbr_,QString abs_,QString primes_)
{
    id=id_;
    nbrvoy=nbr_;
    absc=abs_;
    primes=primes_;
}



bool etatpers::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PERSONNELS_ETAT (ID_PERS, NBRE_VOYAGE_RESERVE, ABSCENCE,PRIMES) "
                    "VALUES (:id, :nom, :prenom,:gsm)");
query.bindValue(":id", res);
query.bindValue(":nom", nbrvoy);
query.bindValue(":prenom", absc);
query.bindValue(":gsm", primes);

return    query.exec();
}
QSqlQueryModel * etatpers::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNELS_ETAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_VOYAGE_RESERVE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ABSCENCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIMES"));

    return model;
}
bool etatpers::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PERSONNELS_ETAT where ID_PERS = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * etatpers::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNELS_ETAT order by ID_PERS asc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_VOYAGE_RESERVE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ABSCENCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIMES"));

    return model;
}
QSqlQueryModel * etatpers::chercher(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
       // QString res= ui->lineEdit->text();
        model->setQuery("select * from PERSONNELS_ETAT where ID_PERS='"+res+"' ");//='"+res+"'

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PERS"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRE_VOYAGE_RESERVE "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ABSCENCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIMES"));
        return model;
}
bool etatpers::update()
{
    QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(id);
             QString editer="Update PERSONNELS_ETAT set" ;
            query.bindValue(":nbrvoy",nbrvoy);
            if(nbrvoy!="")
            {
                editer+=" NBRE_VOYAGE_RESERVE = :nbrvoy" ;
                first=1 ;
            }

            query.bindValue(":absc",absc);
            if(absc!=""&& first!=0)
                editer+=" ,ABSCENCE= :absc" ;
            else if (absc!=""&&first==0)
              {
                editer+=" ABSCENCE= :absc" ;
                first=1 ;
              }
                 query.bindValue(":prime",primes);
                 if(primes!=""&& first!=0)
                     editer+=" ,PRIMES = :prime" ;
                 else if (primes!="" && first==0)
                 {
                    editer+=" PRIMES = :prime" ;
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
             query.bindValue(":nbrvoy",nbrvoy);
            query.bindValue(":absc",absc);
                 query.bindValue(":prime",primes);


             return query.exec();
}

