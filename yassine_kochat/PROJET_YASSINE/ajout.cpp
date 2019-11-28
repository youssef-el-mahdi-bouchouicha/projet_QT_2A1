#include "ajout.h"
#include "ui_ajout.h"
#include "QMessageBox"
#include "client.h"
#include "affichage.h"
#include "ui_affichage.h"
#include <QSystemTrayIcon>
#include "mailing/SmtpMime"
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
Ajout::Ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
    mysysteme=new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
}

Ajout::~Ajout()
{
    delete ui;
}

void Ajout::on_pushButton_clicked()
{

 // ///////////////////////////////////////////

    QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/lenovo/Desktop/CrudGestionPersonnel3/pdf1");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        font.setPixelSize(35);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        painter.drawText(20,300,"cin: ");
        painter.drawText(20,500,"nom:");
        painter.drawText(20,650,"prenom:");
        painter.drawText(20,800,"adresse:");
        painter.drawText(20,1000,"age:");
        painter.drawText(20,1250,"telephone:");
        painter.drawText(20,1450,"statut familiale:");
        painter.drawText(20,1650,"identifiant:");
       // int cin=ui->cin->text().toInt();
        QString cin_pdf=QString::number(cin);

     //   int age=ui->age->text().toInt();
        QString age_pdf=QString::number(age);

        //int tel=ui->telephone->text().toInt();
        QString tel_pdf=QString::number(tel);

        QString nom_pdf=ui->nom->text();
        QString prenom_pdf=ui->prenom->text();
        QString adresse_pdf=ui->adresse->text();
        QString statut_pdf=ui->s_familiale->text();

        font.setPixelSize(15);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(20,350,cin_pdf);
        painter.drawText(20,550,nom_pdf);
        painter.drawText(20,700,prenom_pdf);
        painter.drawText(20,850,adresse_pdf);
        painter.drawText(20,1050,age_pdf);
        painter.drawText(20,1300,tel_pdf);
        painter.drawText(20,1700,statut_pdf);


        QImage image("C:/Users/lenovo/Desktop/CrudGestionPersonnel3");
        painter.drawImage(100,50,image);

        painter.end();

        qDebug()<<"le pdf a ete cree";
        QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

                      ui->message->setText("PDF CREER");


///////////////////////////////////////////
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail=ui->lineEdit_mail->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString date=ui->dateEdit->text();
    int tel=ui->lineEdit_tel->text().toInt();
    int age=ui->lineEdit_age->text().toInt();
  client c(id,nom,prenom,tel,mail,adresse,date,age);
  bool test=c.ajouter();
  if(test)
{

mysysteme->showMessage(tr("notification"),tr("ajout avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

smtp.setUser("yassine.kochat@esprit.tn");
smtp.setPassword("yassine123");


MimeMessage message;

message.setSender(new EmailAddress("yassine.kochat@esprit.tn", "KOCHAT YASSINE"));
message.addRecipient(new EmailAddress("melek.abid@esprit.tn", "Yassine"));
message.setSubject("SmtpClient for Qt - Demo");

MimeText text;

text.setText("Hi,\n SAHBY KOCHAT WAHDOU SEC.\n");

message.addPart(&text);

smtp.connectToHost();
smtp.login();
smtp.sendMail(message);
smtp.quit();

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


