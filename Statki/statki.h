#ifndef STATKI_H
#define STATKI_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Statki; }
QT_END_NAMESPACE

class Statki : public QMainWindow
{
    Q_OBJECT

public:
    Statki(QWidget *parent = nullptr);
    ~Statki();
    QTcpSocket *socket;

private slots:
    void on_btn_Connect_clicked();

private:
    Ui::Statki *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;

    void displayError(QAbstractSocket::SocketError socketError);
};
#endif // STATKI_H
