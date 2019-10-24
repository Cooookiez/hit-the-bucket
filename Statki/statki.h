#ifndef STATKI_H
#define STATKI_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Statki; }
QT_END_NAMESPACE

class Statki : public QMainWindow
{
    Q_OBJECT

public:
    Statki(QWidget *parent = nullptr);
    ~Statki();

private:
    Ui::Statki *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};
#endif // STATKI_H
