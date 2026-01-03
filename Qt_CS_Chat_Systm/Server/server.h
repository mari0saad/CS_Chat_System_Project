#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

class ClientSession;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);
    void start(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
};


#endif // SERVER_H
