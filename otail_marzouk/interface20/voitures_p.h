#ifndef VOITURES_P_H
#define VOITURES_P_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class VOITURES_P
{
public:
    VOITURES_P();

     VOITURES_P(int,QString,QString,QString,QString);
     //int get_id_voiture();
   int get_matricule();
     QString get_responsable();
     QString get_date_achat();
     QString get_marque();
     QString get_date_e(){return date_entretient;}
     bool ajouter();
     QSqlQueryModel * afficher();
     QSqlQueryModel * trier();
      QSqlQueryModel * chercher(QString);
      int rech(int);

     bool supprimer(int);
     bool update();
private:
     //int id_voiture;
    /* QString*/int  matricule;
     QString responsable;
     QString date_achat;
     QString marque;
     QString date_entretient;
};

#endif // VOITURES_P_H
