#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>

namespace Ui {
class Ajout;
}
class QSystemTrayIcon;
class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = nullptr);
    ~Ajout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ajout *ui;
    QSystemTrayIcon * mysysteme;
};

#endif // AJOUT_H
