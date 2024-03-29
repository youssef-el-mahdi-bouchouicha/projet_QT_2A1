#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_label();

    void on_activer_bip_clicked();

    void on_des_bip_clicked();

private:
    Ui::MainWindow *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A;
};
#endif // MAINWINDOW_H
