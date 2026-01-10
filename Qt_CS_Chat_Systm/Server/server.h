#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "commandregistry.h"

class ClientSession;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);
    void start(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    CommandRegistry m_registry;
};


#endif // SERVER_H
