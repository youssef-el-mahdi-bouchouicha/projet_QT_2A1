#ifndef GROUPE_H
#define GROUPE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class groupe
{public:
    groupe();
    groupe(QString,int,int,int);
    QString get_type();


    int get_nombre();
    int get_idpersonnel();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update();
private:
    QString type;

    int nombre;
    int id_personnel;
    int id;

};

#endif // GROUPE_H
