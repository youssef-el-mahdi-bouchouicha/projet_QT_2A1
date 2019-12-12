#ifndef AJOUTERCONTACTS_H
#define AJOUTERCONTACTS_H

#include <QDialog>

namespace Ui {
class Ajoutercontacts;
}
class QSystemTrayIcon;

class Ajoutercontacts : public QDialog
{
    Q_OBJECT

public:
    explicit Ajoutercontacts(QWidget *parent = nullptr);
    ~Ajoutercontacts();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Ajoutercontacts *ui;
    QSystemTrayIcon* mysystem;
};

#endif // AJOUTERCONTACTS_H
