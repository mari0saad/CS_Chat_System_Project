#include "server.h"
#include <QDebug>
#include "clientsession.h"
#include <QThread>
#include "serverconfig.h"
#include "authcommand.h"
#include "createcommand.h"
#include "readcommand.h"
#include "writecommand.h"
#include "appendcommand.h"
#include "deletecommand.h"
#include "listcommand.h"
#include "renamecommand.h"
#include "infocommand.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    m_registry.registerCommand("AUTH", [] {
        return std::make_unique<AuthCommand>();
    });
    m_registry.registerCommand("CREATE", [] {
        return std::make_unique<CreateCommand>();
    });
    m_registry.registerCommand("READ", [] {
        return std::make_unique<ReadCommand>();
    });
    m_registry.registerCommand("WRITE", [] {
        return std::make_unique<WriteCommand>();
    });
    m_registry.registerCommand("APPEND", [] {
        return std::make_unique<AppendCommand>();
    });
    m_registry.registerCommand("DELETE", [] {
        return std::make_unique<DeleteCommand>();
    });
    m_registry.registerCommand("LIST", [] {
        return std::make_unique<ListCommand>();
    });
    m_registry.registerCommand("INFO", [] {
        return std::make_unique<InfoCommand>();
    });
}

void Server::start(quint16 port)
{
    ServerConfig::ensureSandboxExists();
    if (listen(QHostAddress::Any, port)) {
        qDebug() << "Server listening on port" << port;
    } else {
        qDebug() << "Server failed to start:" << errorString();
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "New client connected, socketDescriptor:" << socketDescriptor;
    auto* session = new ClientSession(socketDescriptor, &m_registry, this);
    session->start();
}
