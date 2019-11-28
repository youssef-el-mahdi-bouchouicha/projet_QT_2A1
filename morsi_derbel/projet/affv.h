#ifndef AFFV_H
#define AFFV_H

#include <QDialog>
#include"resvoy.h"

namespace Ui {
class affv;
}

class affv : public QDialog
{
    Q_OBJECT

public:
    explicit affv(QWidget *parent = nullptr);
    ~affv();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_recher_textEdited(const QString &arg1);

private:
    Ui::affv *ui;
    resvoy tmpresvoy;
};

#endif // AFFV_H
