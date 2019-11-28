#ifndef AFFICHER_H
#define AFFICHER_H
#include "g_bus.h"
#include <QDialog>

namespace Ui {
class afficher;
}

class afficher : public QDialog
{
    Q_OBJECT

public:
    explicit afficher(QWidget *parent = nullptr);
    ~afficher();

private slots:
    //void on_listWidget_itemClicked(QListWidgetItem *item);
   // G_BUS a;

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

private:
    Ui::afficher *ui;
      G_BUS a;
};

#endif // AFFICHER_H
