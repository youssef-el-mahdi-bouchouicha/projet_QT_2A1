#include "supptransp.h"
#include "ui_supptransp.h"

supptransp::supptransp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supptransp)
{
    ui->setupUi(this);
}

supptransp::~supptransp()
{
    delete ui;
}
