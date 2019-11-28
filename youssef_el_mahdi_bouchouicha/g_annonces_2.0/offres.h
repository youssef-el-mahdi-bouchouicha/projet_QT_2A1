#ifndef OFFRES_H
#define OFFRES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Offres
{
public:
    Offres();
    Offres(int id,QString periode,QString type_voyageurs,QString  date_dept,QString date_retour,QString descr );
    QString get_periode(){return periode;}
    QString get_type_voyageurs(){return type_voyageurs;}
    QString get_date_dept(){return date_dep;}
    QString get_date_retour(){return date_retour;}
    QString get_description(){return description;}
    int get_id_offre(){return id_offre;}
    bool ajouter_offres();
    QSqlQueryModel * afficher_offres();
    QSqlQueryModel * afficher_offre_trier();
    bool supprimer_offres(int);
    QSqlQueryModel * chercher_offre(int );
    int rech_offre(int );


private:
    QString type_voyageurs,periode,date_dep,date_retour,description;
    int id_offre;
};

#endif // OFFRES_H
