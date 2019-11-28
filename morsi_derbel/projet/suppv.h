#ifndef SUPPV_H
#define SUPPV_H

#include <QDialog>
#include "resvoy.h"

namespace Ui {
class suppv;
}

class suppv : public QDialog
{
    Q_OBJECT

public:
    explicit suppv(QWidget *parent = nullptr);
    ~suppv();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::suppv *ui;
    resvoy tmpresvoy;
};

#endif // SUPPV_H
