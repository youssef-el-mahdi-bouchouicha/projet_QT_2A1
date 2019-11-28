#include "contact_autres.h"

CONTACT_AUTRES::CONTACT_AUTRES()
{
    ID_RESP=0;
    NOM_RESP=" ";
    PRENOM_RESP=" ";
    OCCUPATION="";
    TYPE="";
    ADDRESSE="";
    E_MAIL="";
    GSM=0;
}
CONTACT_AUTRES::CONTACT_AUTRES(int ID_RESP,QString NOM_RESP,QString PRENOM_RESP,QString OCCUPATION,QString TYPE,QString ADDRESSE,QString E_MAIL,int GSM)
{
this->ID_RESP=ID_RESP;
    this->NOM_RESP=NOM_RESP;
    this->PRENOM_RESP=PRENOM_RESP;
    this->OCCUPATION=OCCUPATION;
    this->TYPE=TYPE;
    this->ADDRESSE=ADDRESSE;
    this->E_MAIL=E_MAIL;
    this->GSM=GSM;

}
int CONTACT_AUTRES::get_ID_RESP()
{
    return ID_RESP;
}
QString CONTACT_AUTRES::get_NOM_RESP()
{
    return NOM_RESP;
}
QString CONTACT_AUTRES::get_PRENOM_RESP()
{
    return PRENOM_RESP;
}
QString CONTACT_AUTRES::get_OCCUPATION()
{
    return OCCUPATION;
}
QString CONTACT_AUTRES::get_TYPE()
{
    return TYPE;
}
QString CONTACT_AUTRES::get_ADDRESSE()
{
    return ADDRESSE;
}
QString CONTACT_AUTRES::get_E_MAIL()
{
    return  E_MAIL;
}
int CONTACT_AUTRES::get_GSM()
{
    return GSM;
}
bool CONTACT_AUTRES::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID_RESP);
QString res2= QString::number(GSM);
CONTACT_AUTRES c;
if(c.recherche(ID_RESP)==0)
{
query.prepare("INSERT INTO CONTACT_AUTRES(ID_RESP,NOM_RESP,PRENOM_RESP,OCCUPATION,TYPE,ADDRESSE,E_MAIL,GSM ) "
                    "VALUES (:id_resp,:nom_resp,:prenom_resp,:occupation,:type,:addresse,:e_mail,:gsm)");
query.bindValue(":id_resp", res);
query.bindValue(":nom_resp", NOM_RESP);
query.bindValue(":prenom_resp", PRENOM_RESP);
query.bindValue(":occupation", OCCUPATION);
query.bindValue(":type", TYPE);
query.bindValue(":addresse", ADDRESSE);
query.bindValue(":e_mail", E_MAIL);
query.bindValue(":gsm", res2);
}
 return    query.exec();
}
QSqlQueryModel * CONTACT_AUTRES::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select *from CONTACT_AUTRES");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESP"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_RESP "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_RESP"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("OCCUPATION"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADDRESSE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("E_MAIL"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("GSM"));
       return model;

}
QSqlQueryModel *CONTACT_AUTRES::chercher_contact(int ref)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("select * from CONTACT_AUTRES WHERE ID_RESP=:ref"));
    query.bindValue(":ref",ref);
      query.exec();
         model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_RESP "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_RESP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("OCCUPATION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADDRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("E_MAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("GSM"));
    return model;

}
QSqlQueryModel * CONTACT_AUTRES::afficher1_trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select *from CONTACT_AUTRES order by ID_RESP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_RESP "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_RESP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("OCCUPATION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADDRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("E_MAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("GSM"));
    return model;
}
bool CONTACT_AUTRES::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
      query.prepare("Delete from CONTACT_AUTRES where ID_RESP = :idd ");
      query.bindValue(":idd", res);
      return    query.exec();

}
bool CONTACT_AUTRES::modifiercontact()
{
    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(ID_RESP);
        QString editer=" UPDATE CONTACT_AUTRES set" ;
        query.bindValue(":nom_resp",NOM_RESP);
        if(NOM_RESP!="")
        {
            editer+=" NOM_RESP= :nom_resp" ;
            first=1 ;
        }
        query.bindValue(":prenom_resp",PRENOM_RESP);
        if(PRENOM_RESP!=""&& first!=0)
            editer+=" ,PRENOM_RESP= :prenom_resp" ;
        else if (PRENOM_RESP!=""&&first==0)
          {
            editer+=" PRENOM_RESP= :prenom_resp" ;
            first=1 ;
          }
        query.bindValue(":occupation",OCCUPATION);
        if(OCCUPATION!=""&& first!=0)
            editer+=" ,OCCUPATION= :occupation" ;
        else if (OCCUPATION!=""&&first==0)
          {
            editer+=" OCCUPATION= :occupation" ;
            first=1 ;
          }
        query.bindValue(":type",TYPE);
        if(TYPE!=""&& first!=0)
            editer+=" ,TYPE= :type" ;
        else if (TYPE!=""&&first==0)
          {
            editer+=" TYPE= :type" ;
            first=1 ;
          }
        query.bindValue(":addresse",ADDRESSE);
        if(ADDRESSE!=""&& first!=0)
            editer+=" ,ADDRESSE= :addresse" ;
        else if (ADDRESSE!=""&&first==0)
          {
            editer+=" ADDRESSE= :addresse" ;
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
        query.bindValue(":gsm",GSM);
        if(GSM!=0&& first!=0)
            editer+=" ,GSM= :gsm" ;
        else if (GSM!=0&&first==0)
          {
            editer+=" GSM= :GSM" ;
            first=1 ;
          }
          editer+=" where ID_RESP = :id_resp" ;
          QByteArray chaine = editer.toLocal8Bit();
          const char *final = chaine.data();
            query.prepare(final);
             query.bindValue(":id_resp",QVariant(res1).toInt());
             query.bindValue(":nom_resp",NOM_RESP);
            query.bindValue(":prenom_resp",PRENOM_RESP);
                 query.bindValue(":occupation",OCCUPATION);
                  query.bindValue(":addresse",ADDRESSE);
             query.bindValue(":type",TYPE);
               query.bindValue(":e_mail",E_MAIL);
            query.bindValue(":gsm",GSM);
            return query.exec();


}
int CONTACT_AUTRES:: recherche(int id)
{
    QSqlQuery query;
    int count =0;
    bool test=0;
    QString idb=QString :: number(id);
    if(query.exec("select ID_HT from  CONTACT_AUTRES where ID_RESP ='"+idb+"'"))
    {
         while(query.next())
                  count++;
                  if(count>=1)
                  test=1;
}
                  return  test;
}
