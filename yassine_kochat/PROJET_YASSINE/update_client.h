#ifndef UPDATE_CLIENT_H
#define UPDATE_CLIENT_H

#include <QDialog>

namespace Ui {
class update_client;
}

class update_client : public QDialog
{
    Q_OBJECT

public:
    explicit update_client(QWidget *parent = nullptr);
    ~update_client();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::update_client *ui;
};

#endif // UPDATE_CLIENT_H
