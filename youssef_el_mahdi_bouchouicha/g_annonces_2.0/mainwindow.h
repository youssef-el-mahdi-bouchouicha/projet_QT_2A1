#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"connexion.h"
#include <QMainWindow>
#include <annonces.h>
#include <offres.h>
#include<events.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_but_clicked();
    void on_supprimer_clicked();

    void on_ajouter_offre_clicked();

    void on_offre_supprimer_but_clicked();

    void on_ajouter_event_but_clicked();

    void on_supprimer_event_but_clicked();

    void on_trier_voy_but_clicked();

    void on_trier_offre_but_clicked();

    void on_trier_event_but_clicked();



    void on_chercher_voy_clicked();

    void on_chercher_event_but_clicked();

    void on_chercher_offre_but_clicked();



    void on_mod_voy_but_clicked();

    void on_stat_event_but_clicked();



private:
    Ui::MainWindow *ui ;
    Annonces tmpannonces;
    Offres tmpoffres ;
    Events tmpevents;
    QSystemTrayIcon * mysysteme;
};
#endif // MAINWINDOW_H
