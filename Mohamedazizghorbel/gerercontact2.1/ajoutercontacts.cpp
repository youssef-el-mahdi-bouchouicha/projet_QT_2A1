#include "ajoutercontacts.h"
#include "ui_ajoutercontacts.h"
#include<QMessageBox>
#include"contact_hebergement_transport.h"
#include<QSystemTrayIcon>
#include"stati.h"
#include<QDebug>
#include "mailing/SmtpMime"
Ajoutercontacts::Ajoutercontacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajoutercontacts)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

Ajoutercontacts::~Ajoutercontacts()
{
    delete ui;
}

void Ajoutercontacts::on_pushButton_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("yassine.kochat@esprit.tn");
    smtp.setPassword("yassine123");


    MimeMessage message;

    message.setSender(new EmailAddress("yassine.kochat@esprit.tn", "MOHAMED AZIZ GHORBEL"));
    message.addRecipient(new EmailAddress("mohamedaziz.ghorbel@esprit.tn", "Yassine"));
    message.setSubject("SmtpClient for Qt - Demo");

    MimeText text;

    text.setText("Hi,\n Test mailing.\n");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();


    int ID_HT = ui->lineEdit->text().toInt();
    QString TYPE= ui->comboBox->currentText();
    int GSM= ui->lineEdit_3->text().toInt();
     QString FAX= ui->lineEdit_4->text();
      QString E_MAIL= ui->lineEdit_5->text();
  QString ADRESSE=ui->lineEdit_6->text();

    CONTACT_HEBERGEMENT_TRANSPORT o(ID_HT,TYPE,GSM,FAX,E_MAIL ,ADRESSE);

bool test= o.ajouter();
if(test)
{
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
    QMessageBox::information(nullptr, QObject::tr("Ajouter un contact "),
                      QObject::tr("Etudiant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter un contact"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void Ajoutercontacts::on_pushButton_3_clicked()
{
    stati s;
    s.exec();
}
