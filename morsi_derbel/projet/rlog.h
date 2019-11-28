#ifndef RLOG_H
#define RLOG_H

#include <QDialog>

namespace Ui {
class Rlog;
}

class Rlog : public QDialog
{
    Q_OBJECT

public:
    explicit Rlog(QWidget *parent = nullptr);
    ~Rlog();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Rlog *ui;
};

#endif // RLOG_H
