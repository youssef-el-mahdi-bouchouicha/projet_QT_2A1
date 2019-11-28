#ifndef RESTR_H
#define RESTR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class restr
{
    int idr;
    QString dat;
    QString dest;
    int idc;
    QString type;
    QString etp;
    int res;

public:

    int get_idr(){return  idr;}
    QString get_dat(){return dat;}
    QString get_dest(){return dest;}
    int get_idc(){return idc;}
    QString get_type(){return type;}
    QString get_etp(){return etp;}
    int get_res(){return res;}
    bool ajouter();

restr(int,QString,QString,int,QString,QString,int);

    restr();
};

#endif // RESTR_H
