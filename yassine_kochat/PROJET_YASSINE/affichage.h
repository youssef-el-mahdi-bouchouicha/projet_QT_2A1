#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "client.h"

#include <QDialog>

namespace Ui {
class Affichage;
}

class Affichage : public QDialog
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = nullptr);
    ~Affichage();

private slots:
    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::Affichage *ui;
    client tmpclient;
};

#endif // AFFICHAGE_H
