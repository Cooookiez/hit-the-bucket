#ifndef MENU_H
#define MENU_H

#include "statki.h"
#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();


private:
    Ui::menu *ui;
    Statki *mDialog;
};

#endif // MENU_H
