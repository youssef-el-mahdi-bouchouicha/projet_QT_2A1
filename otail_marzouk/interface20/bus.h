#ifndef BUS_H
#define BUS_H

#include <QDialog>

namespace Ui {
class bus;
}
class QSystemTrayIcon;
class bus : public QDialog
{
    Q_OBJECT

public:
    explicit bus(QWidget *parent = nullptr);
    ~bus();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::bus *ui;
    QSystemTrayIcon * mysystem;
};

#endif // BUS_H
