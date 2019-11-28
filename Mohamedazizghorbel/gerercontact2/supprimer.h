#ifndef SUPPRIMER_H
#define SUPPRIMER_H
#include"contact_hebergement_transport.h"
#include <QDialog>

namespace Ui {
class supprimer;
}

class supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer(QWidget *parent = nullptr);
    ~supprimer();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::supprimer *ui;
    CONTACT_HEBERGEMENT_TRANSPORT a;
};

#endif // SUPPRIMER_H
