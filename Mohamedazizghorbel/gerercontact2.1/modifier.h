#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier *ui;
};

#endif // MODIFIER_H
