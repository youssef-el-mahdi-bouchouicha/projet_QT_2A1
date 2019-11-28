#ifndef AFFICHE1_H
#define AFFICHE1_H
#include"contact_autres.h"
#include <QDialog>

namespace Ui {
class affiche1;
}

class affiche1 : public QDialog
{
    Q_OBJECT

public:
    explicit affiche1(QWidget *parent = nullptr);
    ~affiche1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::affiche1 *ui;
    CONTACT_AUTRES a;
};

#endif // AFFICHE1_H
