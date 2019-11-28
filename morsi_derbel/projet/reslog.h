#ifndef RESLOG_H
#define RESLOG_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reslog
{
    int idr,idc,idco,nbr,res;
    QString dat,etp;
public:
    reslog();
    reslog(int,int,int,QString,int,QString,int);
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * rechav(QString);
    QSqlQueryModel * tri();
    bool imprimer(QString);

    bool supprimer(int);
    bool update();
};

#endif // RESLOG_H
