#include "statki.h"
#include "ui_statki.h"
#include <QMessageBox>
#include <QSound>
#include <QtMultimedia/QMediaPlayer>
#include <iostream>

Statki::Statki(QWidget *parent): QMainWindow(parent), ui(new Ui::Statki){

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->gv_ocean_local->setScene(scene);
//    ui->gv_ocean_local->setSceneRect(0 ,0 ,20, 40);

    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);

    blackPen.setWidth(2);

    rectangle = scene->addRect(0, 5, 10, 5, blackPen, redBrush);
    qreal w = scene->width();
    qreal width = scene->sceneRect().width();

}

Statki::~Statki(){

    delete ui;

}

void Statki::play_sound()
{
    //QSound dzwiek("Ring06.wav");
    //dzwiek.play();
    QSound::play("../sound/Ring06.wav");
    qDebug() << "App path : " << qApp->applicationDirPath();
//    printf(qApp->applicationDirPath())
//    std::cout << "qApp->applicationDirPath();" << qApp->applicationDirPath() << std::endl;
}
void Statki::play_sound_1()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../sound/Ring06.wav"));
    player->setVolume(50);
    player->play();
    qDebug() << "App path : " << qApp->applicationDirPath();
}

void Statki::on_btn_Connect_clicked()
{
    play_sound_1();
}
