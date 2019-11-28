#ifndef CONTACT_HEBERGEMENT_TRANSPORT_H
#define CONTACT_HEBERGEMENT_TRANSPORT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class CONTACT_HEBERGEMENT_TRANSPORT
{
public:
    CONTACT_HEBERGEMENT_TRANSPORT();
    CONTACT_HEBERGEMENT_TRANSPORT(int,QString,int,QString,QString,QString );
    int get_ID_HT();
    QString get_TYPE();
    QString get_E_MAIL();
    int get_GSM();
      QString  get_FAX();
        QString get_ADRESSE();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifiercontact();
        QSqlQueryModel* chercher_contact_heb_trans(int);
         QSqlQueryModel *  afficher_trier();
         int rech(int);


private:
        QString  TYPE;
        QString E_MAIL;
        QString FAX ;
        QString ADRESSE;
         int GSM;
        int ID_HT;
};

#endif // CONTACT_HEBERGEMENT_TRANSPORT_H
