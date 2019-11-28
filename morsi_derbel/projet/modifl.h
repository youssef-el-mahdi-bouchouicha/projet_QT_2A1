#ifndef MODIFL_H
#define MODIFL_H

#include <QDialog>

namespace Ui {
class modifl;
}

class modifl : public QDialog
{
    Q_OBJECT

public:
    explicit modifl(QWidget *parent = nullptr);
    ~modifl();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::modifl *ui;
};

#endif // MODIFL_H
