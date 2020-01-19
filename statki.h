#ifndef STATKI_H
#define STATKI_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDialog>
//#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Statki; }
QT_END_NAMESPACE

class Statki : public QMainWindow
{
    Q_OBJECT

public:
    Statki(QWidget *parent = nullptr);
    ~Statki();
    //QTcpSocket *socket;
    void open_menu();

private slots:
    //void on_btn_Connect_clicked();

    //void on_pushButton_clicked();


    void on_pushButton_clicked();

private:
    Ui::Statki *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;


    //void displayError(QAbstractSocket::SocketError socketError);
};
#endif // STATKI_H
