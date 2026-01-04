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
    buffer.append(socket->readAll());

    while (true) {
        int newlineIndex = buffer.indexOf('\n');
        if (newlineIndex == -1) {
            break;
        }
        QByteArray line = buffer.left(newlineIndex);
        buffer.remove(0, newlineIndex + 1);
        QString commandLine = QString::fromUtf8(line).trimmed();
        QString response = dispatcher.dispatch(commandLine, context);
        qDebug() << "Command received:" << commandLine;
        socket->write(response.toUtf8());
    }
}
