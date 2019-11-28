#ifndef SUPPTRANSP_H
#define SUPPTRANSP_H

#include <QDialog>

namespace Ui {
class supptransp;
}

class supptransp : public QDialog
{
    Q_OBJECT

public:
    explicit supptransp(QWidget *parent = nullptr);
    ~supptransp();

private:
    Ui::supptransp *ui;
};

#endif // SUPPTRANSP_H
