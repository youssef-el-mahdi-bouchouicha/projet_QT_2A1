#ifndef MODIFIER1_H
#define MODIFIER1_H

#include <QDialog>

namespace Ui {
class modifier1;
}

class modifier1 : public QDialog
{
    Q_OBJECT

public:
    explicit modifier1(QWidget *parent = nullptr);
    ~modifier1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier1 *ui;
};

#endif // MODIFIER1_H
