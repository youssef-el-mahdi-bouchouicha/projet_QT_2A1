#ifndef MODIFV_H
#define MODIFV_H

#include <QDialog>

namespace Ui {
class modifv;
}

class modifv : public QDialog
{
    Q_OBJECT

public:
    explicit modifv(QWidget *parent = nullptr);
    ~modifv();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::modifv *ui;
};

#endif // MODIFV_H
