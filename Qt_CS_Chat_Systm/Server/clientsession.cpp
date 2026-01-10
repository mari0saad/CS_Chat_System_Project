#include "clientsession.h"
#include <QTcpSocket>
#include <QDebug>
#include <QThread>


ClientSession::ClientSession(qintptr socketDescriptor, CommandRegistry* registry, QObject* parent)
    : QObject(parent),m_registry(registry)
    {
        // Create socket
        m_socket = new QTcpSocket(this);
        m_socket->setSocketDescriptor(socketDescriptor);
        m_context.fileService = new FileService();
        m_context.authService = new AuthService();
        m_context.isAuthenticated = false;

        connect(m_socket, &QTcpSocket::readyRead, this, &ClientSession::onReadyRead);
        connect(m_socket, &QTcpSocket::disconnected, this, &ClientSession::onDisconnected);
    }


void ClientSession::start()
{
    qDebug() << "Client session started in thread:" << QThread::currentThread();
}

void ClientSession::onReadyRead()
{
    while (m_socket->canReadLine()) {

        QString line = m_socket->readLine().trimmed();
        if (line.isEmpty())
            continue;

        ParsedCommand cmd;

        if (line.startsWith("{")) {
            cmd = m_jsonParser.parse(line);
        } else {
            cmd = m_textParser.parse(line);
        }

        QString response;

        auto command = m_registry->createCommand(cmd);
        if (!command) {
            response = "ERROR 400 Unknown command";
        } else {
            response = command->execute(&m_context, cmd);
        }

        m_socket->write(response.toUtf8() + "\n");
    }
}


void ClientSession::onDisconnected()
{
    qDebug() << "Client disconnected";
    m_socket->deleteLater();
    deleteLater();
}


