#ifndef CLIENTSESSION_H
#define CLIENTSESSION_H

#include <QObject>
#include <QTcpSocket>
#include "commanddispatcher.h"
#include "clientcontext.h"

class ClientSession : public QObject
{
    Q_OBJECT
public:
    explicit ClientSession(qintptr socketDescriptor, QObject* parent = nullptr);
public slots:
    void start();

signals:
    void finished();

private slots:
    void readData();

private:
    QTcpSocket* socket = nullptr;
    qintptr socketDescriptor;
    ClientContext context;
    CommandDispatcher dispatcher;
    QByteArray buffer;

};


#endif // CLIENTSESSION_H
