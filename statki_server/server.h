#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtDebug>
#include "mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>

class MainWindow;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    MainWindow* mainWindow;

signals:

public slots:
    void readyRead();
    void disconnected();

protected:
    void incomingConnection(int sockedfd);

private:
    QSet<QTcpSocket*> clients;
    QTcpServer *server;

};

#endif // SERVER_H
