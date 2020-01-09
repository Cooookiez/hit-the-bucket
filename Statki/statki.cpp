#include "statki.h"
#include "ui_statki.h"
#include <QMessageBox>
#include <QSound>
#include <QtMultimedia/QMediaPlayer>

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


//    scene->setSceneRect(0, 0, qreal(20), qreal(40));
//    rectangle = scene->addRect(0, 0, 5, 10, redBrush, greenBrush);

//    scene = new QGraphicsScene(this);
//    ui->gv_ocean_local->setScene(scene);
    qreal w = scene->width();
    qreal width = scene->sceneRect().width();
//    QString ww = QString::number(w);

//    QBrush greenBrush(Qt::green);
//    QBrush blueBrush(Qt::blue);
//    QPen outlinePen(Qt::black);
//    outlinePen.setWidth(2);

//    rectangle = scene->addRect(0, 0, 300, 250, outlinePen, blueBrush);

//    text = scene->addText(ww, QFont("Arial", 20) );
//    // movable text
//    text->setFlag(QGraphicsItem::ItemIsMovable);

    socket = new QTcpSocket(this);

}

Statki::~Statki(){

    delete ui;

}

void Statki::play_sound()
{
    //QSound dzwiek("Ring06.wav");
    //dzwiek.play();
    QSound::play("c:/wywal/Ring06.wav");
}
void Statki::play_sound_1()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("c:/wywal/Ring06.wav"));
    player->setVolume(50);
    player->play();
}

void Statki::on_btn_Connect_clicked()
{
    //play_sound();
    play_sound_1();
    auto host = ui->textEdit_IP->toPlainText();
    auto port = quint16( ui->textEdit_Port->toPlainText().toInt() );
    socket->connectToHost(host, port);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

    QString message = "Gracz dołączył do hosta";
    socket->write(message.toUtf8());
}
void Statki::displayError ( QAbstractSocket::SocketError socketError )
{
    switch (socketError) {
         case QAbstractSocket::RemoteHostClosedError:
             break;
         case QAbstractSocket::HostNotFoundError:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The host was not found. Please check the "
                                         "host name and port settings."));
             break;
         case QAbstractSocket::ConnectionRefusedError:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The connection was refused by the peer. "
                                         "Make sure the fortune server is running, "
                                         "and check that the host name and port "
                                         "settings are correct."));
             break;
         default:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The following error occurred: %1.")
                                      .arg(socket->errorString()));
         }


}
