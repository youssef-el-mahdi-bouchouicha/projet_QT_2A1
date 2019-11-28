#include "g_bus.h"
#include <QString>
G_BUS::G_BUS()
{
id_bus=0;
matricule="";
date_achat="";
etat="";
marque="";
type="";
disponibilite="";
kilometrage="";
date_entretient="";
}
G_BUS::G_BUS(int id_,QString matricule_,QString etat_,QString date_achat_,QString marque_,QString type_,QString dispo_,QString kilo_,QString date_e_)
{
    this->id_bus=id_;
    this->matricule=matricule_;
    this->etat=etat_;
    this->date_achat=date_achat_;
    this->marque=marque_;
    this->type=type_;
    this->disponibilite=dispo_;
    this->kilometrage=kilo_;
    this->date_entretient=date_e_;
}
int  G_BUS::get_id_bus()
{
    return  id_bus;
}
QString G_BUS :: get_matricule()
{
    return  matricule;
}
QString G_BUS:: get_etat()
{
    return etat;
}
QString G_BUS :: get_date_achat()
{
    return date_achat;
}
QString G_BUS :: get_marque()
{
    return marque;
}
/*int id_bus;
     QString matricule;
     QString etat;
     QString date_achat;
     QString marque;
};*/
bool  G_BUS::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_bus);
G_BUS b;
if(b.rech(id_bus)==0)
{
query.prepare("INSERT INTO BUS (ID_BUS, MATRICULE, ETAT,DATE_ACHAT,KILOMETRAGE,TYPE,DISPONIBILITE,MARQUE,DATE_DERNIER_ENTRETIENT) "
                    "VALUES (:id_bus, :matricule, :etat,:date_achat,:kilometrage,:type,:disponibilite,:marque,:date_entretient)");
query.bindValue(":id_bus", res);
query.bindValue(":matricule", matricule);
query.bindValue(":etat", etat);
query.bindValue(":date_achat", date_achat);
query.bindValue(":marque", marque);
query.bindValue(":kilometrage", kilometrage);
query.bindValue(":type", type);
query.bindValue(":disponibilite", disponibilite);
query.bindValue(":date_entretient", date_entretient);
}




return    query.exec();
}
QSqlQueryModel * G_BUS::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
//QString res ui->linedit->text()
model->setQuery("select * from BUS  ");//='"+res+"'
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_BUS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_DERNIER_ENTRETIENT"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("MARQUE"));
    return model;
}
bool G_BUS::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from BUS where ID_BUS = :id_bus ");
query.bindValue(":id_bus", res);
return    query.exec();
}
bool G_BUS::update()
{
    QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(id_bus);
             QString editer="Update BUS set" ;
            query.bindValue(":type",type);
            if(type!="")
            {
                editer+=" TYPE = :type" ;
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

                 query.bindValue(":kilometrage",kilometrage);
                 if(kilometrage!=""&& first!=0)
                     editer+=" ,KILOMETRAGE = :kilometrage" ;
                 else if (kilometrage!="" && first==0)
                 {
                    editer+=" KILOMETRAGE = :kilometrage" ;
                    first=1 ;
                 }

                   query.bindValue(":date_entretient",date_entretient);
                   if(date_entretient!=""&& first!=0)
                       editer+=" ,DATE_DERNIER_ENTRETIENT = :date_entretient" ;
                   else if (date_entretient!=""&&first==0)
                   {
                     editer+=" DATE_DERNIER_ENTRETIENT = :date_entretient" ;
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

                   query.bindValue(":disponibilite",disponibilite);
                   if(disponibilite!=""&& first!=0)
                       editer+=" ,DISPONIBILITE = :disponibilite" ;
                   else if (disponibilite!=""&&first==0)
                   {
                     editer+=" DISPONIBILITE = :disponibilite" ;
                     first=1 ;
                   }



                   query.bindValue(":etat",etat);
                   if(etat!=""&& first!=0)
                       editer+=" ,ETAT = :etat" ;
                   else if (etat!=""&&first==0)
                   {
                     editer+=" ETAT = :etat" ;
                     first=1 ;
                   }

                   query.bindValue(":matricule",matricule);
                   if(matricule!=""&& first!=0)
                       editer+=" ,MATRICULE = :matricule" ;
                   else if (matricule!=""&&first==0)
                   {
                     editer+=" MATRICULE = :matricule" ;
                     first=1 ;
                   }

                   editer+=" where ID_BUS = :id_bus" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();

                 /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                               QObject::tr(final
                                           ), QMessageBox::Cancel); */

               query.prepare(final);

                   //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

             query.bindValue(":id_bus",QVariant(res1).toInt());
             query.bindValue(":marque",marque);
            query.bindValue(":date_achat",date_achat);
                 query.bindValue(":date_entretient",date_entretient);
                   query.bindValue(":matricule",matricule);
                   query.bindValue(":type",type);
                   query.bindValue(":etat",etat);
                   query.bindValue(":disponibilite",disponibilite);
                   query.bindValue(":kilometrage",kilometrage);

             return query.exec();
}
int G_BUS ::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString idb=QString::number(id);
        if(query.exec("select ID_BUS from BUS where  ID_BUS='" +idb +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}
QSqlQueryModel * G_BUS::chercher(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
       // QString res= ui->lineEdit->text();
        model->setQuery("select * from BUS where ID_BUS='"+res+"' ");//='"+res+"'
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_BUS"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_DERNIER_ENTRETIENT"));
        return model;
}
QSqlQueryModel * G_BUS::trier()
{QSqlQueryModel * model= new QSqlQueryModel();
//QString res ui->linedit->text()
model->setQuery("select * from BUS order by ID_BUS asc ");//='"+res+"'
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_BUS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DERNIER_ENTRETIENT"));
    return model;
}
