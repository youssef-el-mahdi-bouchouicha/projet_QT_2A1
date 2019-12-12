#include "gerercontact.h"
#include "ui_gerercontact.h"
#include"ajoutercontacts.h"
#include"affiche.h"
#include"supprimer.h"
#include"modifier.h"
#include"ajoutercontacts1.h"
#include"affiche1.h"
#include"supprimer1.h"
#include"modifier1.h"
Gerercontact::Gerercontact(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gerercontact)
{
    ui->setupUi(this);
    animation = new QPropertyAnimation(ui->label_2,"geometry");
        animation->setDuration(10000);
        animation->setStartValue(ui->label_2->geometry());
        animation->setEndValue(QRect(350,200,0,71));
        animation->start();
}

Gerercontact::~Gerercontact()
{
    delete ui;
}


void Gerercontact::on_pushButton_clicked()
{
    Ajoutercontacts c;
    c.setWindowTitle("ajoutercontacts");
    c.exec();
}

void Gerercontact::on_pushButton_3_clicked()
{
        affiche a;
        a.setWindowTitle("affiche");
        a.exec();
}

void Gerercontact::on_pushButton_4_clicked()
{
    supprimer b;
    b.setWindowTitle("supprimer");
    b.exec();
}

void Gerercontact::on_pushButton_2_clicked()
{
    modifier y;
    y.setWindowTitle("modifier");
    y.exec();
}

void Gerercontact::on_pushButton_5_clicked()
{
    ajoutercontacts1 t;
    t.setWindowTitle("ajoutercontacts1");
    t.exec();
}

void Gerercontact::on_pushButton_7_clicked()
{
    affiche1 a;
    a.setWindowTitle("affiche1");
    a.exec();


}

void Gerercontact::on_pushButton_8_clicked()
{
    supprimer1 z;
    z.setWindowTitle("supprimer1");
    z.exec();

}

void Gerercontact::on_pushButton_6_clicked()
{
    modifier1 a;
    a.setWindowTitle("modifier1");
    a.exec();
}
