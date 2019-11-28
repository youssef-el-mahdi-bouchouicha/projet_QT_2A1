#ifndef SUPPRIMER_CLIENT_H
#define SUPPRIMER_CLIENT_H

#include <QDialog>
#include "client.h"

namespace Ui {
class supprimer_client;
}

class supprimer_client : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_client(QWidget *parent = nullptr);
    ~supprimer_client();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::supprimer_client *ui;
    client tmpclients;
};

#endif // SUPPRIMER_CLIENT_H
