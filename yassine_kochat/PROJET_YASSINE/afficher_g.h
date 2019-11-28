#ifndef AFFICHER_G_H
#define AFFICHER_G_H

#include <QDialog>
#include "groupe.h"

namespace Ui {
class afficher_g;
}

class afficher_g : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_g(QWidget *parent = nullptr);
    ~afficher_g();

private:
    Ui::afficher_g *ui;
    groupe tmpgroupe;
};

#endif // AFFICHER_G_H
