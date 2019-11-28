#ifndef RV_H
#define RV_H

#include <QDialog>

namespace Ui {
class rv;
}
class QSystemTrayIcon ;

class rv : public QDialog
{
    Q_OBJECT

public:
    explicit rv(QWidget *parent = nullptr);
    ~rv();

private slots:
    void on_pushButton_3_clicked();

  //  void on_lineEdit_idc_cursorPositionChanged(int arg1, int arg2);

  //  void on_pushButton_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rv *ui;
    QSystemTrayIcon *mysystem;
};

#endif // RV_H
