#include "statki.h"
#include "ui_statki.h"
#include <QMessageBox>

Statki::Statki(QWidget *parent): QMainWindow(parent), ui(new Ui::Statki){

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->gv_ocean_local->setScene(scene);
    ui->gv_ocean_local->setSceneRect(0 ,0 ,30, 30);

    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);

    blackPen.setWidth(2);
    //QGraphicsRectItem group[64];
    rectangle = new QGraphicsRectItem(0,0,37.5,37.5);
    rectangle->setPos(-133.5,-133.5);
    scene->addItem(rectangle);
    auto rectangle2 = new QGraphicsRectItem(0,0,37.5,37.5);
    rectangle2->setPos(-133.5,-96);
    scene->addItem(rectangle2);
    auto rectangle3 = new QGraphicsRectItem(0,0,37.5,37.5);
    rectangle3->setPos(-133.5,-58.5);
    scene->addItem(rectangle3);



//rectangle = scene->addRect(1000,1000, 37.5, 37.5, blackPen, redBrush);





      //scene->setSceneRect(0, 0, qreal(20), qreal(40));
//    rectangle = scene->addRect(0, 0, 5, 10, redBrush, greenBrush);

//    scene = new QGraphicsScene(this);
//    ui->gv_ocean_local->setScene(scene);
    //qreal w = scene->width();
    //qreal width = scene->sceneRect().width();
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


void Statki::on_btn_Connect_clicked()
{
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
