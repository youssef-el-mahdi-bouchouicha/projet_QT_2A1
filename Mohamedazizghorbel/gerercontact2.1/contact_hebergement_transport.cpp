#include "contact_hebergement_transport.h"

CONTACT_HEBERGEMENT_TRANSPORT::CONTACT_HEBERGEMENT_TRANSPORT()
{
ID_HT= 0;
TYPE="";
E_MAIL="";
GSM=0;
FAX="";
ADRESSE="";
}
CONTACT_HEBERGEMENT_TRANSPORT::CONTACT_HEBERGEMENT_TRANSPORT(int ID_HT,QString TYPE,int GSM,QString FAX,QString E_MAIL,QString ADRESSE)
{
    this->ID_HT=ID_HT;
    this->TYPE=TYPE;
    this->E_MAIL=E_MAIL;
    this->GSM=GSM;
    this->FAX=FAX;
    this->ADRESSE=ADRESSE;

}
QString CONTACT_HEBERGEMENT_TRANSPORT::get_FAX()
{
    return FAX;
}
int CONTACT_HEBERGEMENT_TRANSPORT::get_ID_HT()
{
    return ID_HT;
}
QString CONTACT_HEBERGEMENT_TRANSPORT::get_E_MAIL()
{
    return E_MAIL;
}
QString CONTACT_HEBERGEMENT_TRANSPORT::get_TYPE()
{
    return TYPE;
}
QString CONTACT_HEBERGEMENT_TRANSPORT::get_ADRESSE()
{
    return ADRESSE;
}
int CONTACT_HEBERGEMENT_TRANSPORT::get_GSM()
{
    return  GSM ;
}


int CONTACT_HEBERGEMENT_TRANSPORT:: rech(int id)
{
    QSqlQuery query;
    int count =0;
    bool test=0;
    QString idb=QString :: number(id);
    if(query.exec("select ID_HT from  CONTACT_HEBERGEMENT_TRANSPORT where ID_HT ='"+idb+"'"))
    {
         while(query.next())
                  count++;
                  if(count>=1)
                  test=1;
}
                  return  test;
}



bool CONTACT_HEBERGEMENT_TRANSPORT::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID_HT);
QString res2= QString::number(GSM);
CONTACT_HEBERGEMENT_TRANSPORT c;
if(c.rech(ID_HT)==0)
{
    query.prepare("INSERT INTO CONTACT_HEBERGEMENT_TRANSPORT(ID_HT,TYPE,GSM,FAX,E_MAIL,ADRESSE ) "
                        "VALUES (:id_ht,:type,:gsm,:Fax,:e_mail,:adresse)");
    query.bindValue(":id_ht", res);
    query.bindValue(":type", TYPE);
    query.bindValue(":gsm", res2);
    query.bindValue(":e_mail", E_MAIL);
    query.bindValue(":Fax", FAX);
    query.bindValue(":adresse", ADRESSE);
}

    return    query.exec();
}
QSqlQueryModel * CONTACT_HEBERGEMENT_TRANSPORT::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select *from CONTACT_HEBERGEMENT_TRANSPORT");
    //model->setQuery("select *from CONTACTHEBERGEMENTTRANSPORT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_HT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("GSM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FAX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("E_MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

        return model;
}
bool CONTACT_HEBERGEMENT_TRANSPORT::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from CONTACT_HEBERGEMENT_TRANSPORT where ID_HT = :idd ");
    query.bindValue(":idd", res);
    return    query.exec();
}
/*bool CONTACT_HEBERGEMENT_TRANSPORT::modifiercontact()
{
    QSqlQuery query;
        int first=0 ;
        QString res1=QString::number(ID_HT);
        QString res1=QString::number(id_bus);

}*/

QSqlQueryModel *CONTACT_HEBERGEMENT_TRANSPORT ::chercher_contact_heb_trans(int ref)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from CONTACT_HEBERGEMENT_TRANSPORT WHERE ID_HT=:ref"));

     query.bindValue(":ref",ref);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_HT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("GSM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("E_MAIL"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("FAX"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));


return model;
 }
QSqlQueryModel * CONTACT_HEBERGEMENT_TRANSPORT::afficher_trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select *from CONTACT_HEBERGEMENT_TRANSPORT order by ID_HT");
    //model->setQuery("select *from CONTACTHEBERGEMENTTRANSPORT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_HT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("GSM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E_MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("FAX"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

        return model;
}
bool CONTACT_HEBERGEMENT_TRANSPORT::modifiercontact()
{
    QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(ID_HT);
            QString editer=" UPDATE CONTACT_HEBERGEMENT_TRANSPORT set" ;
            query.bindValue(":type",TYPE);
            if(TYPE!="")
            {
                editer+=" TYPE= :type" ;
                first=1 ;
            }
            query.bindValue(":gsm",GSM);
            if(GSM!=0&& first!=0)
                editer+=" ,GSM= :gsm" ;
            else if (GSM!=0&&first==0)
              {
                editer+=" GSM= :GSM" ;
                first=1 ;
              }
            query.bindValue(":e_mail",E_MAIL);
            if(E_MAIL!=""&& first!=0)
                editer+=" ,E_MAIL= :e_mail" ;
            else if (E_MAIL!=""&&first==0)
              {
                editer+=" E_MAIL= :e_mail" ;
                first=1 ;
              }
            query.bindValue(":fax",FAX);
            if(FAX!=""&& first!=0)
                editer+=" ,FAX= :fax" ;
            else if (FAX!=""&&first==0)
              {
                editer+=" FAX= :fax" ;
                first=1 ;
              }
            query.bindValue(":adresse",ADRESSE);
            if(ADRESSE!=""&& first!=0)
                editer+=" ,ADRESSE= :adresse" ;
            else if (ADRESSE!=""&&first==0)
              {
                editer+=" ADRESSE= :adresse" ;
                first=1 ;
              }
               editer+=" where ID_HT = :id_ht" ;
               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();
               query.prepare(final);
               query.bindValue(":id_ht",QVariant(res1).toInt());
               query.bindValue(":type",TYPE);
              query.bindValue(":gsm",GSM);
                   query.bindValue(":e_mail",E_MAIL);
                     query.bindValue(":fax",FAX);
                      query.bindValue(":adresse",ADRESSE);
                      return query.exec();

}

