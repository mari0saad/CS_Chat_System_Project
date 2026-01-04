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
}

void Client::readyRead()
{
    while (socket->canReadLine()) {
        QByteArray line = socket->readLine();
        qDebug() << line.trimmed();
    }
}

void Client::disconnected()
{
    qDebug() << "------Disconnected from server------";
}

void Client::sendLine(const QString& line)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write((line + "\n").toUtf8());
    }
}
