#include "suppl.h"
#include "ui_suppl.h"
#include "reslog.h"
#include <QMessageBox>
#include"modifl.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QFile>
#include <QPainter>
#include<QSystemTrayIcon>
#include <QDesktopServices>
#include <QUrl>
#include"mailing/SmtpMime"


suppl::suppl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::suppl)
{
    ui->setupUi(this);
    mysystem= new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
}

suppl::~suppl()
{
    delete ui;
}

void suppl::on_pushButton_2_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);


        smtp.setUser("julietta.corva@gmail.com");
        smtp.setPassword("elwesselmrass0213");



        MimeMessage message;

        message.setSender(new EmailAddress("julietta.corva@gmail.com", "JULIETTA"));
        message.addRecipient(new EmailAddress("morsi.derbel@esprit.tn", "MORSI"));
        message.setSubject("SmtpClient for Qt - Demo");



        MimeText text;

        text.setText("Hi,\n TEST MAILING.\n");



        message.addPart(&text);


        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();

    int id = ui->impr->text().toInt();
    bool test=r.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void suppl::on_pushButton_3_clicked()
{
    modifl ml;
    ml.setModal(true);
    ml.exec();
}

void suppl::on_pushButton_5_clicked()
{
    QString rese=ui->impr->text();



    QString idr;
    QString idc;
    QString nbr;
    QString idco;
    QString res;
    QString dat;
    QString etp;




    QSqlQuery query ("SELECT ID_RES, ID_CLIENT, NBR_NUIT, DATE_RES, ID_CONT, ETAT_PAY, RESTE FROM RESLOG where ID_RES='"+rese+"' ");
    while (query.next()) {



     idr=query.value(0).toString();
     idc=query.value(1).toString();
     nbr=query.value(2).toString();
     dat=query.value(3).toString();
     idco=query.value(4).toString();
     etp=query.value(5).toString();
     res=query.value(6).toString();

}



    QPdfWriter pdf("F:/Bureau/projet c++/projet/file3.pdf");
    QPainter painter(&pdf);
    painter.drawPixmap(QRect(-10,-10,13000,20000),QPixmap("F:/Bureau/projet c++/projet/abcd.jpg"));
    painter.setPen(Qt::red);
    painter.setFont(QFont("Cooper Black",50));
    painter.drawText(2500,1000,"VOUCHER");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Bahnschrift SemiBold",30));
    painter.drawText(3100,3000,"ID_client: ");
    painter.drawText(7000,3000,idc);
    painter.drawText(3100,4000,"Nbre de Nuité: ");
    painter.drawText(7000,4000,nbr);
    painter.drawText(3100,5000,"date: ");
    painter.drawText(7000,5000,dat);
    painter.drawText(3100,6000,"ID_hotel: ");
    painter.drawText(7000,6000,idco);
    painter.drawText(3100,7000,"Etat payement: ");
    painter.drawText(7000,7000,etp);
    painter.drawText(3100,8000,"Reste a payer: ");
    painter.drawText(7000,8000,res);
    painter.drawPixmap(QRect(2300,9000,4800,4800),QPixmap("F:/Bureau/projet c++/projet/qrcode-dizziweb.png"));







    painter.end();


    mysystem->showMessage(tr("notification"),tr("fichier pdf pret"));




}
