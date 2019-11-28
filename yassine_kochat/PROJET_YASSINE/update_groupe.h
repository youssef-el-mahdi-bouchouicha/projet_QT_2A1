#ifndef UPDATE_GROUPE_H
#define UPDATE_GROUPE_H

#include <QDialog>

namespace Ui {
class update_groupe;
}

class update_groupe : public QDialog
{
    Q_OBJECT

public:
    explicit update_groupe(QWidget *parent = nullptr);
    ~update_groupe();

private slots:
    void on_pushButton_18_clicked();

private:
    Ui::update_groupe *ui;
};

#endif // UPDATE_GROUPE_H
