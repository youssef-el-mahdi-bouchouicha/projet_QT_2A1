#ifndef RESVOY_H
#define RESVOY_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class resvoy
{
public:
    resvoy();
    resvoy(int,int,int,int,QString);
    int get_idr();
    int get_idv();
    int get_idc();
    int get_res();
    QString get_etp();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * rechav(QString);
    QSqlQueryModel * tri();

    bool supprimer(int);
    bool update();
private:
    int idv,idr,idc,res;
    QString etp;
};

#endif // RESVOY_H
