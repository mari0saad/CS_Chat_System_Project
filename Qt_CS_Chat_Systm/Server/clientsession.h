#ifndef CLIENTSESSION_H
#define CLIENTSESSION_H

#include <QObject>
#include <QTcpSocket>

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
    QTcpSocket* socket;
    qintptr socketDescriptor;
};


#endif // CLIENTSESSION_H
