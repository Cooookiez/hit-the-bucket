#include "menu.h"
#include "ui_menu.h"
#include <QApplication>
#include "statki.h"
#include <QDebug>
#include <QPixmap>
#include <QDir>
#include <QDebug>
#include <QString>

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    QString path = QDir::currentPath()+"/images/yacht.jpg";
    //qDebug()<<path;
    //QPixmap bkgnd("/home/nkrauze/Pulpit/hit-the-bucket-Natalia-Krauze/Statki/images/yacht.jpg");
    QPixmap bkgnd(path);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //ui->label->setStyleSheet("{color: ##ffffff}");
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked() // naprawić hide(), ponieważ nie działa
{

    //Menu.setModal(false);
    //Menu.exec();
    //Statki *w;
    hide();
    mDialog = new Statki(this);
    mDialog->show();
    //hide_me();
    //qDebug()<<this;
    //qDebug()<<mDialog;
    //this->close();
    //this->hide();
    //menu::close();
    //w.show();
    //w.open_game();
}
