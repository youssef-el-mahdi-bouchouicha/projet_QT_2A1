#ifndef AFFL_H
#define AFFL_H
#include"reslog.h"

#include <QDialog>

namespace Ui {
class affl;
}

class affl : public QDialog
{
    Q_OBJECT

public:
    explicit affl(QWidget *parent = nullptr);
    ~affl();

private slots:
    void on_recher1_clicked();

    void on_pushButton_17_clicked();

    void on_recher_2_textEdited(const QString &arg1);

private:
    Ui::affl *ui;
    reslog tmpreslog;


};

#endif // AFFL_H
