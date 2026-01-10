#ifndef CLIENTSESSION_H
#define CLIENTSESSION_H

#include <QObject>
#include <QTcpSocket>
#include "commanddispatcher.h"
#include "clientcontext.h"
#include "commandregistry.h"
#include "textcommandparser.h"
#include "jsoncommandparser.h"

class ClientSession : public QObject
{
    Q_OBJECT
public:
    explicit ClientSession(qintptr socketDescriptor, CommandRegistry* registry, QObject* parent = nullptr);
public slots:
    void start();

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    QTcpSocket* m_socket = nullptr;

    // Parsing
    TextCommandParser m_textParser;
    JsonCommandParser m_jsonParser;

    // Dispatch
    CommandRegistry* m_registry = nullptr;

    // Per-client state
    ClientContext m_context;
};


#endif // CLIENTSESSION_H
