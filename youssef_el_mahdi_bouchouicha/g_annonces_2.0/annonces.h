#ifndef ANNONCES_H
#define ANNONCES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Annonces
{
public:
    Annonces();
    Annonces(int id,QString type,QString destination,QString  date_dept,QString date_retour,QString id_bus,QString description );
    QString get_type(){return type;}
    QString get_destination(){return destination;}
    QString get_date_dept(){return date_dep;}
    QString get_date_retour(){return date_retour;}
    QString get_id_bus(){return id_bus;}
    QString get_description(){return description;}
    int get_id_voyage(){return id_voyage;}
    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_voy_trier();
    bool supprimer(int);
    QSqlQueryModel * chercher_voyage(int );
   int rech_voy(int);
    bool modifier_voy(int,QString ,QString ,QString  ,QString ,QString ,QString );
private:
    QString type,destination,date_dep,date_retour,id_bus,description;
    int id_voyage;
};

#endif // ANNONCES_H
