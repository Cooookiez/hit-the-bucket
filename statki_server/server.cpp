#include "server.h"
#include <QTcpSocket>

Server::Server(QObject *parent) : QTcpServer(parent)
{
    mainWindow->addMsg("Start...");
}

void Server::incomingConnection(int sockedfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(sockedfd);
    clients.insert(client);

    mainWindow->addMsg("New client form: "+client->peerAddress().toString());

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected), this, SLOT(disconnected()));
}

void Server::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        mainWindow->addMsg(line);
    }
}

void Server::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    mainWindow->addMsg("Client disconnected:" + client->peerAddress().toString());

    clients.remove(client);
}

//void Server::newConnection()
//{
//    QTcpSocket *socket = server->nextPendingConnection();
//    socket->write("Hello client");
//    socket->flush();
//    socket->waitForBytesWritten(3000);
//    socket->close();
//}
