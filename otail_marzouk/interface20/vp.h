#ifndef VP_H
#define VP_H

#include <QDialog>

namespace Ui {
class vp;
}
class QSystemTrayIcon;
class vp : public QDialog
{
    Q_OBJECT

public:
    explicit vp(QWidget *parent = nullptr);
    ~vp();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::vp *ui;
    QSystemTrayIcon  *mysystem;
};

#endif // VP_H
