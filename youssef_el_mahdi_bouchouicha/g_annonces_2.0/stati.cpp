#include "stati.h"
#include "ui_stati.h"
#include "ui_mainwindow.h"
stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}


int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ANNONCE_EVENTS where TYPE_VOYAGEURS ='groupe jeune'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ANNONCE_EVENTS where TYPE_VOYAGEURS  ='Famille'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ANNONCE_EVENTS where TYPE_VOYAGEURS  ='couple'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("Groupe jeune") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("Famille") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("Couple") ;

}

void stati::on_pushButton_clicked()
{
    hide();
}
