#ifndef RTRANSP_H
#define RTRANSP_H

#include <QDialog>

namespace Ui {
class rtransp;
}

class rtransp : public QDialog
{
    Q_OBJECT

public:
    explicit rtransp(QWidget *parent = nullptr);
    ~rtransp();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::rtransp *ui;
};

#endif // RTRANSP_H
