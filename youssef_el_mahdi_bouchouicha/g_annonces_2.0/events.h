#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Events
{
public:
    Events();
    Events(int id,int nbre_jour,QString type_voyageurs,int prix,QString descr );
    QString get_description (){return description ;}
    QString get_type_voyageurs(){return type_voyageurs;}
    int get_prix_event(){return prix;}
    int get_id_offre(){return id_event;}
    int get_nbre_jours(){return nbre_jour;}
    bool ajouter_event();
    QSqlQueryModel * afficher_event();
     QSqlQueryModel * afficher_event_trier();
     QSqlQueryModel * chercher_event(int );
    int rech_event(int);
    bool supprimer_event(int);
private:
    QString type_voyageurs,description;
    int id_event,nbre_jour ,prix;
};

#endif // EVENTS_H
