#ifndef RTRANSPO_H
#define RTRANSPO_H

#include <QDialog>

namespace Ui {
class rtranspo;
}

class rtranspo : public QDialog
{
    Q_OBJECT

public:
    explicit rtranspo(QWidget *parent = nullptr);
    ~rtranspo();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::rtranspo *ui;
};

#endif // RTRANSPO_H
