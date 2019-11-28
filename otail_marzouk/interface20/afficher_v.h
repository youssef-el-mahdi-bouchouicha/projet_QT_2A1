#ifndef AFFICHER_V_H
#define AFFICHER_V_H
#include"voitures_p.h"
#include <QDialog>

namespace Ui {
class afficher_v;
}

class afficher_v : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_v(QWidget *parent = nullptr);
    ~afficher_v();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::afficher_v *ui;
    VOITURES_P p;
};

#endif // AFFICHER_V_H
