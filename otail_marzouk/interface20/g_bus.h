#ifndef G_BUS_H
#define G_BUS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class G_BUS
{
public:
    G_BUS();
     G_BUS(int,QString,QString,QString,QString,QString,QString,QString,QString);
     int get_id_bus();
     QString get_matricule();
     QString get_etat();
     QString get_date_achat();
     QString get_marque();
     QString get_type(){return type ;}
    QString  get_disponibilite(){return disponibilite;}
    QString  get_kilometrage(){return  kilometrage ;}
    QString  get_date_entretient(){return date_entretient;}

     bool ajouter();
     QSqlQueryModel * afficher();
     QSqlQueryModel * chercher(QString);
     QSqlQueryModel * trier();
     bool supprimer(int);
      bool update();
      int rech(int);
private:
     int id_bus;
     QString matricule;
     QString etat;
     QString date_achat;
     QString marque;
     QString type;
     QString disponibilite;
     QString kilometrage;
     QString date_entretient;
};

#endif // G_BUS_H
