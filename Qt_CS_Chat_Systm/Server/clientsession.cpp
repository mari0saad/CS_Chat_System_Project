#include "clientsession.h"
#include <QTcpSocket>
#include <QDebug>
#include <QThread>


ClientSession::ClientSession(qintptr descriptor, QObject* parent)
    : QObject(parent), socketDescriptor(descriptor)
{
}

void ClientSession::start()
{
    socket = new QTcpSocket(this);

    if (!socket->setSocketDescriptor(socketDescriptor)) {
        qDebug() << "Failed to set socket descriptor";
        emit finished();
        return;
    }

    connect(socket, &QTcpSocket::readyRead, this, &ClientSession::readData);
    connect(socket, &QTcpSocket::disconnected, this, &ClientSession::finished);

    qDebug() << "Client session started in thread:" << QThread::currentThread();
}

void ClientSession::readData()
{
    QByteArray data = socket->readAll();
    qDebug() << "Received from client:" << data;
    socket->write("Server received: " + data); //ACK
}
