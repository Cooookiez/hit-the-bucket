#include "statki.h"
#include "ui_statki.h"
#include "menu.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <algorithm>

Statki::Statki(QWidget *parent): QMainWindow(parent), ui(new Ui::Statki){

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->gv_ocean_local->setScene(scene);
    ui->gv_ocean_local->setSceneRect(0 ,0 ,30, 30);

    scene2 = new QGraphicsScene(this);
    ui->gv_ocean_remote->setScene(scene2);
    ui->gv_ocean_remote->setSceneRect(0 ,0 ,30, 30);

    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QColor seablue(0,102,153);
    //QPen blackPen(Qt::black);
    QPen bluePen(seablue);
    bluePen.setWidth(1);
    QGraphicsRectItem *group[64];
    QGraphicsRectItem *group2[64];
    std::fill_n(group,64,new QGraphicsRectItem(0,0,37.5,37.5));
    std::fill_n(group2,64,new QGraphicsRectItem(0,0,37.5,37.5));
    //qDebug()<<group[6];
    //QString rect = "rectangle";
    for(int i = 0; i<=64; i++)
    {
        //QString s = QString::number(i);
        //auto r = rect+s;
        auto rect = new QGraphicsRectItem(0,0,37.5,37.5);
        auto rect2 = new QGraphicsRectItem(0,0,37.5,37.5);
        if(i<=8)
        {
            group[i]->setPos(-133.5,-133.5+i*(37.5));
            rect->setPos(-133.5,-133.5+i*(37));
            group2[i]->setPos(-133.5,-133.5+i*(37.5));
            rect2->setPos(-133.5,-133.5+i*(37));
        }
        else if(i>8 and i<=16)
        {
            group[i]->setPos(-133.5+37.5,-133.5+(i-9)*(37));
            rect->setPos(-133.5+37.5,-133.5+(i-9)*(37));
            group2[i]->setPos(-133.5+37.5,-133.5+(i-9)*(37));
            rect2->setPos(-133.5+37.5,-133.5+(i-9)*(37));
        }
        else if(i>16 and i<=24)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(2*37.5),-133.5+(i-17)*(37));
            rect->setPos(-133.5+(2*37.5),-133.5+(i-17)*(37));
            group2[i]->setPos(-133.5+(2*37.5),-133.5+(i-17)*(37));
            rect2->setPos(-133.5+(2*37.5),-133.5+(i-17)*(37));
            //qDebug()<<rect;

        }
        else if(i>24 and i<=32)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(3*37.5),-133.5+(i-25)*(37));
            rect->setPos(-133.5+(3*37.5),-133.5+(i-25)*(37));
            group2[i]->setPos(-133.5+(3*37.5),-133.5+(i-25)*(37));
            rect2->setPos(-133.5+(3*37.5),-133.5+(i-25)*(37));
            //qDebug()<<rect;

        }
        else if(i>32 and i<=40)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(4*37.5),-133.5+(i-33)*(37));
            rect->setPos(-133.5+(4*37.5),-133.5+(i-33)*(37));
            group2[i]->setPos(-133.5+(4*37.5),-133.5+(i-33)*(37));
            rect2->setPos(-133.5+(4*37.5),-133.5+(i-33)*(37));
            //qDebug()<<rect;

        }
        else if(i>40 and i<=48)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(4*37.5),-133.5+(i-41)*(37));
            rect->setPos(-133.5+(5*37.5),-133.5+(i-41)*(37));
            group2[i]->setPos(-133.5+(4*37.5),-133.5+(i-41)*(37));
            rect2->setPos(-133.5+(5*37.5),-133.5+(i-41)*(37));
            //qDebug()<<rect;

        }
        else if(i>48 and i<=56)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(5*37.5),-133.5+(i-49)*(37));
            rect->setPos(-133.5+(6*37.5),-133.5+(i-49)*(37));
            group2[i]->setPos(-133.5+(5*37.5),-133.5+(i-49)*(37));
            rect2->setPos(-133.5+(6*37.5),-133.5+(i-49)*(37));
            //qDebug()<<rect;

        }
        else if (i>56 and i<=64)
        {
            //qDebug()<<i;
            group[i]->setPos(-133.5+(6*37.5),-133.5+(i-57)*(37));
            rect->setPos(-133.5+(7*37.5),-133.5+(i-57)*(37));
            group2[i]->setPos(-133.5+(6*37.5),-133.5+(i-57)*(37));
            rect2->setPos(-133.5+(7*37.5),-133.5+(i-57)*(37));
            //qDebug()<<rect;
        }
        scene->addItem(rect);
        scene2->addItem(rect2);
        rect->setPen(bluePen);
        rect2->setPen(bluePen);
        //auto rec = group[i];
        //qDebug()<<type(group[i]);
        //scene->addItem(rect);
    }
    //scene->addItem(group[0]);
    //scene->addItem(group[1]);
    //scene->addItem(group[2]);
    //rectangle = new QGraphicsRectItem(0,0,37.5,37.5);
    //group[0] = rectangle;
    //rectangle->setPos(-133.5,-133.5);
    //scene->addItem(rectangle);
    //auto rectangle2 = new QGraphicsRectItem(0,0,37.5,37.5);
    //rectangle2->setPos(-133.5,-96);
    //scene->addItem(rectangle2);
    //auto rectangle3 = new QGraphicsRectItem(0,0,37.5,37.5);
    //rectangle3->setPos(-133.5,-58.5);
    //scene->addItem(rectangle3);



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

    //socket = new QTcpSocket(this);

}

Statki::~Statki(){

    delete ui;

}


//void Statki::on_btn_Connect_clicked()
//{
//    auto host = ui->textEdit_IP->toPlainText();
//    auto port = quint16( ui->textEdit_Port->toPlainText().toInt() );
//    socket->connectToHost(host, port);
//    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

//    QString message = "Gracz dołączył do hosta";
//    socket->write(message.toUtf8());
//}
//void Statki::displayError ( QAbstractSocket::SocketError socketError )
//{
//    switch (socketError) {
//         case QAbstractSocket::RemoteHostClosedError:
//             break;
//         case QAbstractSocket::HostNotFoundError:
//             QMessageBox::information(this, tr("Fortune Client"),
//                                      tr("The host was not found. Please check the "
//                                         "host name and port settings."));
//             break;
//         case QAbstractSocket::ConnectionRefusedError:
//             QMessageBox::information(this, tr("Fortune Client"),
//                                      tr("The connection was refused by the peer. "
//                                         "Make sure the fortune server is running, "
//                                         "and check that the host name and port "
//                                         "settings are correct."));
//             break;
//         default:
//             QMessageBox::information(this, tr("Fortune Client"),
//                                      tr("The following error occurred: %1.")
//                                      .arg(socket->errorString()));
//         }


//}

void Statki::open_menu()
{
    hide();
    menu Menu;
    //Menu.show();
    Menu.setModal(true);
    Menu.exec();
}


void Statki::on_pushButton_clicked()
{
    open_menu();
}
