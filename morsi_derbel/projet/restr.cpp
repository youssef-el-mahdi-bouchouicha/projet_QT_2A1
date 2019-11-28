#include "restr.h"

restr::restr()
{

}


restr::restr(int idr,QString dat,QString dest,int idc,QString type,QString etp,int res)
{
    this->idr=idr;
    this->dat=dat;
    this->dest=dest;
    this->idc=idc;
    this->type=type;
    this->etp=etp;
    this->res=res;


}


bool restr::ajouter()
                  {
                  QString idr_= QString::number(idr);
                  QString idc_= QString::number(idc);
                  QString res_= QString::number(res);

                  QSqlQuery query;
                  query.prepare("INSERT INTO RESTRANSP (ID_RES, DATE_RES, DESTINATION, ID_CLIENT, TYPE, ETAT_PAY, RESTE) "
                                      "VALUES (:idr, :dat, :dest, :idc, :type, :etp, :res)");
                  query.bindValue(":idr", idr_);
                  query.bindValue(":dat", dat);
                  query.bindValue(":dest", dest);
                  query.bindValue(":idc", idc_);
                  query.bindValue(":type", type);
                  query.bindValue(":etp", etp);
                  query.bindValue(":res", res_);

                  return    query.exec();
                  }
