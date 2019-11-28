#include "reslog.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QFile>
#include <QPainter>
#include<QSystemTrayIcon>
#include <QDesktopServices>
#include <QUrl>

reslog::reslog()
{

}
reslog::reslog(int idr,int idc,int nbr,QString dat,int idco,QString etp,int res)
{
    this->idr=idr;
    this->idc=idc;
    this->nbr=nbr;
    this->dat=dat;
    this->idco=idco;
    this->etp=etp;
    this->res=res;

}

bool reslog::ajouter()
                  {
                  QString idr_= QString::number(idr);
                  QString idc_= QString::number(idc);
                  QString nbr_= QString::number(nbr);
                  QString idco_= QString::number(idco);
                  QString res_= QString::number(res);
                  QSqlQuery query;
                  query.prepare("INSERT INTO RESLOG (ID_RES, ID_CLIENT, NBR_NUIT, DATE_RES, ID_CONT, ETAT_PAY, RESTE) "
                                      "VALUES (:idr, :idc, :nbr, :dat, :idco, :etp, :res)");
                  query.bindValue(":idr", idr_);
                  query.bindValue(":idc", idc_);
                  query.bindValue(":nbr", nbr_);
                  query.bindValue(":dat", dat);
                  query.bindValue(":idco", idco_);
                  query.bindValue(":etp", etp);
                  query.bindValue(":res", res_);

                  return    query.exec();
                  }

QSqlQueryModel * reslog::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESLOG");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_NUIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CONT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_PAY"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("RESTE"));
    return model;
}

QSqlQueryModel * reslog::tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESLOG order by ID_RES desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_NUIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CONT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_PAY"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("RESTE"));
    return model;
}

QSqlQueryModel * reslog::rechercher(QString rech)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESLOG where ID_RES='"+rech+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_NUIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CONT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_PAY"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("RESTE"));
    return model;
}
QSqlQueryModel * reslog::rechav(QString agr1)
{
    if(agr1=="")
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from RESLOG");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_NUIT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CONT"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_PAY"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("RESTE"));
        return  model;
    }
    else {


    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RESLOG where (ID_RES LIKE '%"+agr1+"%') OR  (ID_CLIENT LIKE '%"+agr1+"%') OR (ID_CONT LIKE '%"+agr1+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_NUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CONT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_PAY"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("RESTE"));
    return  model;
    }
}


bool reslog::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from RESLOG where ID_RES = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool reslog::modifier()
{
    QSqlQuery query;
        int first=0 ;
        QString idr_= QString::number(idr);

        QString editer="Update RESLOG set" ;
            query.bindValue(":ID_CLIENT",idc);
            if(idc!=0)
            {
                editer+=" ID_CLIENT = :idc" ;
                first=1 ;
            }

            query.bindValue(":nbr",nbr);
            if(nbr!=0&& first!=0)
                editer+=" ,NBR_NUIT= :nbr" ;
            else if (nbr !=0&&first==0)
              {
                editer+=" NBR_NUIT= :nbr" ;
                first=1 ;
              }

            query.bindValue(":dat",dat);
            if(nbr!=0&& first!=0)
                editer+=" ,DATE_RES= :dat" ;
            else if (nbr !=0&&first==0)
              {
                editer+=" DATE_RES= :dat" ;
                first=1 ;
              }

            query.bindValue(":idco",idco);
            if(nbr!=0&& first!=0)
                editer+=" ,ID_CONT= :idco" ;
            else if (nbr !=0&&first==0)
              {
                editer+=" ID_CONT= :idco" ;
                first=1 ;
              }

                 query.bindValue(":etp",etp);
                 if(etp!=""&& first!=0)
                     editer+=" ,ETAT_PAY = :etp" ;
                 else if (etp!="" && first==0)
                 {
                    editer+=" ETAT_PAY = :etp" ;
                    first=1 ;
                 }

                   query.bindValue(":res",res);
                   if(res!=0&& first!=0)
                       editer+=" ,RESTE = :res" ;
                   else if (res!=0&&first==0)
                   {
                     editer+=" RESTE = :res" ;
                     first=1 ;
                   }

                   editer+=" where ID_RES = :idr" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();

                 /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                               QObject::tr(final
                                           ), QMessageBox::Cancel); */

                query.prepare(final);

                   //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

             query.bindValue(":idr",QVariant(idr).toInt());
             query.bindValue(":idc",idc);
            query.bindValue(":nbr",nbr);
            query.bindValue(":dat",dat);
            query.bindValue(":idco",idco);
                 query.bindValue(":etp",etp);
                   query.bindValue(":res",res);

             return query.exec();
}

