#ifndef CHERCHER_BUS_H
#define CHERCHER_BUS_H
#include"g_bus.h"
#include <QDialog>

namespace Ui {
class chercher_bus;
}

class chercher_bus : public QDialog
{
    Q_OBJECT

public:
    explicit chercher_bus(QWidget *parent = nullptr);
    ~chercher_bus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chercher_bus *ui;
      G_BUS a;
};

#endif // CHERCHER_BUS_H
