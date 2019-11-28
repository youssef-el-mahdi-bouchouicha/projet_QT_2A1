#ifndef SUPPRIMER_G_H
#define SUPPRIMER_G_H

#include <QDialog>
#include "groupe.h"

namespace Ui {
class supprimer_g;
}

class supprimer_g : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_g(QWidget *parent = nullptr);
    ~supprimer_g();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::supprimer_g *ui;
    groupe tmpgroupe;
};

#endif // SUPPRIMER_G_H
