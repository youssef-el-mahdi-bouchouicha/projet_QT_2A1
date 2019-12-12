#ifndef AJOUTERCONTACTS1_H
#define AJOUTERCONTACTS1_H

#include <QDialog>

namespace Ui {
class ajoutercontacts1;
}
class QSystemTrayIcon;
class   QMediaPlayer;

class ajoutercontacts1 : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutercontacts1(QWidget *parent = nullptr);
    ~ajoutercontacts1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ajoutercontacts1 *ui;
     QSystemTrayIcon * mysystem;
};

#endif // AJOUTERCONTACTS1_H
