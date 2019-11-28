#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client
{public:
    client();
    client(int,QString,QString,int,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    QString get_adresse();
    QString get_date();
    int get_id();
    int get_tel();
     int get_age();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * chercher(int);
     QSqlQueryModel * afficher_tri_par_id();
     int rech(int);
private:
    QString nom,prenom,mail,adresse,date;
    int id;
    int tel,age;

};

#endif // CLIENT_H
