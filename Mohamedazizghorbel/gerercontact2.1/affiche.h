#ifndef AFFICHE_H
#define AFFICHE_H
#include"contact_hebergement_transport.h"
#include <QDialog>

namespace Ui {
class affiche;
}

class affiche : public QDialog
{
    Q_OBJECT

public:
    explicit affiche(QWidget *parent = nullptr);
    ~affiche();

private slots:
 void on_pushButton_clicked();

 void on_pushButton_2_clicked();

private:
    Ui::affiche *ui;
CONTACT_HEBERGEMENT_TRANSPORT e;
};

#endif // AFFICHE_H
