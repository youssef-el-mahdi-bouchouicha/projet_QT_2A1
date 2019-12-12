#ifndef SUPPRIMER1_H
#define SUPPRIMER1_H
#include"contact_autres.h"

#include <QDialog>

namespace Ui {
class supprimer1;
}

class supprimer1 : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer1(QWidget *parent = nullptr);
    ~supprimer1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimer1 *ui;
    CONTACT_AUTRES a;
};

#endif // SUPPRIMER1_H
