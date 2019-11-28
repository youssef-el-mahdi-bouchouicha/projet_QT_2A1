#include "resvoy.h"

resvoy::resvoy()
{

}
resvoy::resvoy(int idr,int idc,int idv,int res,QString etp)
{
    this->idr=idr;
    this->idc=idc;
    this->idv=idv;
    this->res=res;
    this->etp=etp;

}

QString resvoy::get_etp(){return etp;}
int resvoy::get_idc(){return idc;}
int resvoy::get_idr(){return idr;}
int resvoy::get_idv(){return idv;}
int resvoy::get_res(){return res;}

bool resvoy::ajouter()
                  {
                  QString idr_= QString::number(idr);
                  QString idv_= QString::number(idv);
                  QString res_= QString::number(res);
                  QString idc_= QString::number(idc);
                  QSqlQuery query;
                  query.prepare("INSERT INTO RESVOY (ID_RES, ID_CLIENT, ID_VOY, ETAT_PAY, RESTE) "
                                      "VALUES (:idr, :idc, :idv, :etp, :res)");
                  query.bindValue(":idr", idr_);
                  query.bindValue(":idv", idv_);
                  query.bindValue(":idc", idc_);
                  query.bindValue(":etp", etp);
                  query.bindValue(":res", res_);

                  return    query.exec();
                  }
QSqlQueryModel * resvoy::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESVOY");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_VOY"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT_PAY"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESTE"));
    return model;
}

QSqlQueryModel * resvoy::rechercher(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from RESVOY where ID_RES='"+res+"' ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_VOY"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT_PAY"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESTE"));
     return model;
}

QSqlQueryModel * resvoy::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RESVOY order by ID_RES desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_VOY"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT_PAY"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESTE"));
     return model;
}

QSqlQueryModel * resvoy::rechav(QString arg1)
{
    if(arg1=="")
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from RESVOY");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_VOY"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT_PAY"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESTE"));
        return  model;
    }
    else {


    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RESVOY where (ID_RES LIKE '%"+arg1+"%') OR  (ID_CLIENT LIKE '%"+arg1+"%') OR (ID_VOY LIKE'%"+arg1+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_VOY"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT_PAY"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESTE"));
    return  model;
    }
}

bool resvoy::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from RESVOY where ID_RES = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool resvoy::modifier()
{
    QSqlQuery query;
        int first=0 ;
        QString idr_= QString::number(idr);

        QString editer="Update RESVOY set" ;
            query.bindValue(":ID_CLIENT",idc);
            if(idc!=0)
            {
                editer+=" ID_CLIENT = :idc" ;
                first=1 ;
            }

            query.bindValue(":idv",idv);
            if(idv!=0&& first!=0)
                editer+=" ,ID_VOY= :idv" ;
            else if (idv !=0&&first==0)
              {
                editer+=" ID_VOY= :idv" ;
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
            query.bindValue(":idv",idv);
                 query.bindValue(":etp",etp);
                   query.bindValue(":res",res);

             return query.exec();
}

