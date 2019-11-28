#ifndef AJOUT_G_H
#define AJOUT_G_H

#include <QDialog>

namespace Ui {
class Ajout_G;
}

class Ajout_G : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout_G(QWidget *parent = nullptr);
    ~Ajout_G();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::Ajout_G *ui;
};

#endif // AJOUT_G_H
