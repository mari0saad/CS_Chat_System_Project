#include "server.h"
#include <QDebug>
#include "clientsession.h"
#include <QThread>

Server::Server(QObject *parent) : QTcpServer(parent)
{
}

void Server::start(quint16 port)
{
    if (listen(QHostAddress::Any, port)) {
        qDebug() << "Server listening on port" << port;
    } else {
        qDebug() << "Server failed to start:" << errorString();
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "New client connected, socketDescriptor:" << socketDescriptor;

    QThread* thread = new QThread;
    ClientSession* session = new ClientSession(socketDescriptor);
    session->moveToThread(thread);

    QObject::connect(thread, &QThread::started, session, &ClientSession::start);
    QObject::connect(session, &ClientSession::finished, thread, &QThread::quit);
    QObject::connect(session, &ClientSession::finished, session, &ClientSession::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}
