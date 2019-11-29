#ifndef ETATPERS_H
#define ETATPERS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class etatpers
{
public:
    etatpers();


    etatpers(int ,QString,QString,QString);
    QString get_nbrvoy();
    QString get_absc();
    int get_id();
    QString get_primes();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier();
     QSqlQueryModel * chercher(QString);
     bool update();

    bool supprimer(int);
private:
    int id;
    QString nbrvoy;
    QString absc;
    QString primes;
};

#endif // ETATPERS_H
