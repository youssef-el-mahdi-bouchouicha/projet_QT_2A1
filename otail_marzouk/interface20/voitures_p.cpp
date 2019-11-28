#include "voitures_p.h"
#include<QString>
VOITURES_P::VOITURES_P()
{
//id_voiture=0;
matricule=0;
marque="";
date_achat="";
responsable="";
}
VOITURES_P::VOITURES_P( int  mat,QString marqu,QString date_a,QString resp,QString date_e)
{
   // this->id_voiture=id;
    this->matricule= mat;
    this->marque=marqu;
    this->date_achat=date_a;
    this->responsable=resp;
    this->date_entretient=date_e;

}

int VOITURES_P :: get_matricule()
{
    return  matricule;
}
QString VOITURES_P:: get_marque()
{
    return marque;
}
QString VOITURES_P :: get_date_achat()
{
    return date_achat;
}
QString VOITURES_P :: get_responsable()
{
    return responsable;
}
bool  VOITURES_P::ajouter()
{
QSqlQuery query;
QString res= QString::number(matricule);
VOITURES_P p;
if(p.rech(matricule)==0)
{
query.prepare("INSERT INTO VOITURES_PERS ( MATRICULE, ID_RESP,MARQUE,DATE_ACHAT,DATE_ENTRETIENT) "
                    "VALUES (:matricule, :responsable, :marque,:date_achat,:date_entretient)");
query.bindValue(":matricule", res);
query.bindValue(":responsable", responsable);
query.bindValue(":marque", marque);
query.bindValue(":date_achat", date_achat);
query.bindValue(":date_entretient", date_entretient);
}
return    query.exec();

}
bool VOITURES_P::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from VOITURES_PERS where MATRICULE = :matricule ");
query.bindValue(":matricule", res);
return    query.exec();
}
QSqlQueryModel * VOITURES_P::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOITURES_PERS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_RESP "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ENTRETIENT"));
    return model;
}

bool VOITURES_P::update()
{
    QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(matricule);
             QString editer="Update VOITURES_PERS set" ;
            query.bindValue(":responsable",responsable);
            if(responsable!="")
            {
                editer+=" ID_RESP = :responsable" ;
                first=1 ;
            }

            query.bindValue(":marque",marque);
            if(marque!=""&& first!=0)
                editer+=" ,MARQUE= :marque" ;
            else if (marque!=""&&first==0)
              {
                editer+=" MARQUE= :marque" ;
                first=1 ;
              }
                 query.bindValue(":date_achat",date_achat);
                 if(date_achat!=""&& first!=0)
                     editer+=" ,DATE_ACHAT = :date_achat" ;
                 else if (date_achat!="" && first==0)
                 {
                    editer+=" DATE_ACHAT = :date_achat" ;
                    first=1 ;
                 }

                   query.bindValue(":date_entretient",date_entretient);
                   if(date_entretient!=""&& first!=0)
                       editer+=" ,DATE_ENTRETIENT = :date_entretient" ;
                   else if (date_entretient!=""&&first==0)
                   {
                     editer+=" DATE_ENTRETIENT = :date_entretient" ;
                     first=1 ;
                   }

                   editer+=" where MATRICULE = :matricule" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();

                 /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                               QObject::tr(final
                                           ), QMessageBox::Cancel); */

               query.prepare(final);

                   //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

             query.bindValue(":matricule",QVariant(res1).toInt());
             query.bindValue(":marque",marque);
            query.bindValue(":date_achat",date_achat);
                 query.bindValue(":date_entretient",date_entretient);
                   query.bindValue(":responsable",responsable);

             return query.exec();
}
QSqlQueryModel * VOITURES_P::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOITURES_PERS order by MATRICULE asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_RESP "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ENTRETIENT"));
    return model;
}
QSqlQueryModel * VOITURES_P::chercher(QString str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOITURES_PERS  where( MATRICULE LIKE '"+str+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_RESP "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ENTRETIENT"));
    return model;
}
int VOITURES_P ::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString idb=QString::number(id);
        if(query.exec("select MATRICULE from VOITURES_PERS where  MATRICULE='" +idb +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}
