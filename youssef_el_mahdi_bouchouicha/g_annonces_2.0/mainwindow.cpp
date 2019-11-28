#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "annonces.h"
#include <QMessageBox>
#include <offres.h>
#include<events.h>
#include <QSystemTrayIcon>
#include"stati.h"
MainWindow::MainWindow(QWidget *parent )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableVoyage->setModel(tmpannonces.afficher());
    ui->tableoffres->setModel(tmpoffres.afficher_offres());
    ui->tableevents->setModel(tmpevents.afficher_event());
    mysysteme=new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

///slots  de voyage
void MainWindow::on_ajouter_but_clicked()
{
    int id_voyage = ui->line_id_voyage->text().toInt();
    QString type= ui->combo_type_voyage->currentText();
    QString destination= ui->line_dest->text();
    QString date_depart= ui->date_dep_voy->text();
    QString date_retour= ui->date_retour_voy->text();
    QString id_bus= ui->line_id_bus->text();
    QString description= ui->combo_descri_voy->currentText();



    Annonces an(id_voyage,type,destination,date_depart,date_retour,id_bus,description);
  bool test=an.ajouter();
  if(test)
{ ui->tableVoyage->setModel(tmpannonces.afficher());//refresh
      mysysteme->showMessage(tr("notification"),tr("ajout voyage avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un voyage"),
                  QObject::tr("voyage ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un voyage"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);





}


void MainWindow::on_supprimer_clicked()
{
    int id_voyage = ui->line_supp_chercher_voy->text().toInt();
    bool test=tmpannonces.supprimer(id_voyage);
    if(test)
    {ui->tableVoyage->setModel(tmpannonces.afficher());//refresh
        mysysteme->showMessage(tr("notification"),tr("suppression de voyage avec succes"));
        QMessageBox::information(nullptr, QObject::tr("Supprimer voyage"),
                    QObject::tr("voyage supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer voyage"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_trier_voy_but_clicked()
{
    ui->tableVoyage->setModel(tmpannonces.afficher_voy_trier());//refresh
            mysysteme->showMessage(tr("notification"),tr("voyage trier avec succes"));

}

void MainWindow::on_chercher_voy_clicked()
{
    int id_voy = ui->line_supp_chercher_voy->text().toInt();
    ui->tableVoyage->setModel(tmpannonces.chercher_voyage(id_voy));
}


void MainWindow::on_mod_voy_but_clicked()
{
   int id_voyage = ui->line_id_voyage->text().toInt();
    QString type= ui->combo_type_voyage->currentText();
    QString destination= ui->line_dest->text();
    QString date_depart= ui->date_dep_voy->text();
    QString date_retour= ui->date_retour_voy->text();
    QString id_bus= ui->line_id_bus->text();
    QString description= ui->combo_descri_voy->currentText();


    Annonces a;
    if(a.rech_voy(id_voyage))
    {
    bool test=a.modifier_voy(id_voyage,type,destination,date_depart,date_retour,id_bus,description);
    if(test)
    {

                ui->tableVoyage->setModel(tmpannonces.afficher());
                QMessageBox::information(nullptr,QObject::tr("voyage modifier"),
                                         QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
    }
}
//////slot des bouton de offre

void MainWindow::on_ajouter_offre_clicked()
{
    int id_offre = ui->line_id_offre->text().toInt();
    QString periode= ui->combo_periode->currentText();
    QString type_voyageur= ui->combo_type_voy_offre->currentText();
    QString date_depart= ui->date_dep_offre->text();
    QString date_retour= ui->date_retour_offre->text();
    QString description= ui->combo_desc_offre->currentText();



    Offres off(id_offre,periode,type_voyageur,date_depart,date_retour,description);
  bool test=off.ajouter_offres();
  if(test)
{ui->tableoffres->setModel(tmpoffres.afficher_offres());//refresh
      mysysteme->showMessage(tr("notification"),tr("ajout offre avec succes"));

QMessageBox::information(nullptr, QObject::tr("Ajouter offre"),
                  QObject::tr("offre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter offre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_offre_supprimer_but_clicked()
{
    int id_offre = ui->line_supp_chercher_offre->text().toInt();
    bool test=tmpoffres.supprimer_offres(id_offre);
    if(test)
    {ui->tableoffres->setModel(tmpoffres.afficher_offres());//refresh
        mysysteme->showMessage(tr("notification"),tr("suppression d'offre avec succes"));

        QMessageBox::information(nullptr, QObject::tr("Supprimer offre"),
                    QObject::tr("offre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer offre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_trier_offre_but_clicked()
{
        ui->tableoffres->setModel(tmpoffres.afficher_offre_trier());//refresh
                mysysteme->showMessage(tr("notification"),tr("offre trier avec succes"));

}
void MainWindow::on_chercher_offre_but_clicked()
{
    int id_offre  = ui->line_supp_chercher_offre->text().toInt();
    ui->tableoffres->setModel(tmpoffres.chercher_offre(id_offre));
}

///slots de events

void MainWindow::on_ajouter_event_but_clicked()
{
    int id_event = ui->line_id_event->text().toInt();
    int nbre_jours=ui->spinBox_event->text().toInt();
    QString type_voyageurs= ui->combo_type_voy_event->currentText();
    int prix = ui->double_spin_event->text().toInt();
    QString description= ui->combo_desc_offre->currentText();

Events ev (id_event,nbre_jours,type_voyageurs,prix,description);
  bool test=ev.ajouter_event();
  if(test)
{ui->tableevents->setModel(tmpevents.afficher_event());//refresh
      mysysteme->showMessage(tr("notification"),tr("ajout event avec succes"));

QMessageBox::information(nullptr, QObject::tr("Ajouter event"),
                  QObject::tr("event ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter event"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_event_but_clicked()
{
    int id_event = ui->line_supp_chercher_event->text().toInt();
    bool test=tmpevents.supprimer_event(id_event);
    if(test)
    {ui->tableevents->setModel(tmpevents.afficher_event());//refresh
        mysysteme->showMessage(tr("notification"),tr("suppression d'event avec succes"));

        QMessageBox::information(nullptr, QObject::tr("Supprimer event"),
                    QObject::tr("event supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer offre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_trier_event_but_clicked()
{
    ui->tableevents->setModel(tmpevents.afficher_event_trier());//refresh
            mysysteme->showMessage(tr("notification"),tr("event trier avec succes"));
}

void MainWindow::on_chercher_event_but_clicked()
{
    int id_event  = ui->line_supp_chercher_event->text().toInt();
    ui->tableevents->setModel(tmpevents.chercher_event(id_event));
}




void MainWindow::on_stat_event_but_clicked()
{
    stati s;
    s.exec();

}


