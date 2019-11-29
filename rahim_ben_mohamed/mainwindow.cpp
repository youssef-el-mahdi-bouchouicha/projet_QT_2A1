#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include<QMessageBox>
#include<QSystemTrayIcon>
#include"etatpers.h"
#include"stati.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmppers.afficher());
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
    ui->tableView_2->setModel(tmpetat.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
     QString gsm= ui->lineEdit_4->text();
  personnel e(id,nom,prenom,gsm);
  bool test=e.ajouter();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));

      ui->tableView->setModel(tmppers.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_5->text().toInt();
    bool test=tmppers.supprimer(id);
    if(test)
    {//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
        ui->tableView->setModel(tmppers.afficher());

        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(tmppers.trier());

}

void MainWindow::on_pushButton_4_clicked()
{
     QString res= ui->lineEdit_6->text();
     ui->tableView->setModel(tmppers.chercher(res));

}

void MainWindow::on_pushButton_8_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
    QString nom= ui->lineEdit_8->text();
    QString prenom= ui->comboBox_3->currentText();
     QString gsm= ui->lineEdit_10->text();
  etatpers e(id,nom,prenom,gsm);
  bool test=e.ajouter();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));

     // ui->tableView->setModel(tmppers.afficher());
      ui->tableView_2->setModel(tmpetat.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_12->text().toInt();
    bool test=tmpetat.supprimer(id);
    if(test)
    {//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
        ui->tableView_2->setModel(tmpetat.afficher());

        QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("personnel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView_2->setModel(tmpetat.trier());

}

void MainWindow::on_pushButton_6_clicked()
{
     QString res= ui->lineEdit_11->text();
      ui->tableView_2->setModel(tmpetat.chercher(res));
}

void MainWindow::on_pushButton_13_clicked()
{
    int id = ui->lineEdit_22->text().toInt();
    QString nom= ui->lineEdit_19->text();
    QString prenom= ui->lineEdit_20->text();
     QString gsm= ui->lineEdit_21->text();
  personnel e(id,nom,prenom,gsm);
  bool test=e.update();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));

      ui->tableView->setModel(tmppers.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajouter un etat pesonnel"),
                  QObject::tr("etat ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un etat"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
    int id = ui->lineEdit_13->text().toInt();
    QString nom= ui->lineEdit_15->text();
    QString prenom= ui->comboBox->currentText();
     QString gsm= ui->lineEdit_14->text();
  etatpers e(id,nom,prenom,gsm);
  bool test=e.update();
  if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));

     // ui->tableView->setModel(tmppers.afficher());
      ui->tableView_2->setModel(tmpetat.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajouter un etat"),
                  QObject::tr("etat ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un etat"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()
{
    stati s;
    s.exec();
}
