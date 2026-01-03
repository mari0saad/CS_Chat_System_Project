#include "client.h"
#include <QDebug>

Client::Client(QObject* parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Client::connected);
    connect(socket, &QTcpSocket::readyRead, this, &Client::readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Client::disconnected);
}

void Client::connectToServer(const QString& host, quint16 port)
{
    qDebug() << "------Connecting to server------" << host << port;
    socket->connectToHost(host, port);
}

void Client::connected()
{
    qDebug() << "------Connected to server------";
    // Send a test message
    socket->write("Hello Server - From the client \n");
}

void Client::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Received from server:" << data;
}

void Client::disconnected()
{
    qDebug() << "------Disconnected from server------";
}
