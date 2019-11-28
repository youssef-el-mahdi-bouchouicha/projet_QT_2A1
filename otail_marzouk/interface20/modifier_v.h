#ifndef MODIFIER_V_H
#define MODIFIER_V_H

#include <QDialog>

namespace Ui {
class modifier_v;
}

class modifier_v : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_v(QWidget *parent = nullptr);
    ~modifier_v();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::modifier_v *ui;
};

#endif // MODIFIER_V_H
