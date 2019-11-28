#ifndef SUPPRIMER_V_H
#define SUPPRIMER_V_H
#include"voitures_p.h"
#include <QDialog>

namespace Ui {
class supprimer_v;
}

class supprimer_v : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_v(QWidget *parent = nullptr);
    ~supprimer_v();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimer_v *ui;
    VOITURES_P v;
};

#endif // SUPPRIMER_V_H
