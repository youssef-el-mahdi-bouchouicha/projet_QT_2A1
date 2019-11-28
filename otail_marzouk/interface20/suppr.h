#ifndef SUPPR_H
#define SUPPR_H

#include <QDialog>
#include "g_bus.h"

namespace Ui {
class suppr;
}

class suppr : public QDialog
{
    Q_OBJECT

public:
    explicit suppr(QWidget *parent = nullptr);
    ~suppr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::suppr *ui;
    G_BUS a;
};

#endif // SUPPR_H
