#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int ,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_gsm();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier();
     QSqlQueryModel * chercher(QString);
     bool update();

    bool supprimer(int);
private:
    int id;
    QString nom;
    QString prenom;
    QString gsm;

};

#endif // PERSONNEL_H
