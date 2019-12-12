#ifndef GERERCONTACT_H
#define GERERCONTACT_H

#include <QMainWindow>
#include<QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class Gerercontact; }
QT_END_NAMESPACE

class Gerercontact : public QMainWindow
{
    Q_OBJECT

public:
    Gerercontact(QWidget *parent = nullptr);
    ~Gerercontact();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Gerercontact *ui;
    QPropertyAnimation * animation;

};
#endif // GERERCONTACT_H
