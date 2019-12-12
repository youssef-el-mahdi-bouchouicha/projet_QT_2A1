#ifndef CONTACT_AUTRES_H
#define CONTACT_AUTRES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class CONTACT_AUTRES
{
public:
    CONTACT_AUTRES();
     CONTACT_AUTRES(int,QString,QString,QString,QString,QString,QString,int);
     int get_ID_RESP();
     QString get_NOM_RESP();
       QString  get_PRENOM_RESP();
       QString get_OCCUPATION();
       QString get_TYPE();
         QString get_ADDRESSE();
         QString get_E_MAIL();
         int get_GSM();
         bool ajouter();
         QSqlQueryModel * afficher();
         QSqlQueryModel *afficher1_trier();
         QSqlQueryModel *checher_avance(QString);
         QSqlQueryModel* chercher_contact(int );
         bool supprimer(int);
         bool modifiercontact();
         int recherche(int);
private:
         int  ID_RESP;
         QString NOM_RESP;
         QString PRENOM_RESP;
         QString OCCUPATION;
         QString TYPE;
         QString ADDRESSE;
         QString E_MAIL;
         int GSM;

};

#endif // CONTACT_AUTRES_H
