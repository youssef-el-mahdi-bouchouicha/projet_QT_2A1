#ifndef SUPPL_H
#define SUPPL_H
#include<QSystemTrayIcon>
#include <QDialog>
#include"reslog.h"

namespace Ui {
class suppl;
}

class suppl : public QDialog
{
    Q_OBJECT

public:
    explicit suppl(QWidget *parent = nullptr);
    ~suppl();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::suppl *ui;
    reslog r;
    QSystemTrayIcon *mysystem;

};

#endif // SUPPL_H
