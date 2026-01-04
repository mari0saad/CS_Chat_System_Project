#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject* parent = nullptr);
    void connectToServer(const QString& host, quint16 port);

private slots:
    void connected();
    void readyRead();
    void disconnected();
public slots:
    void sendLine(const QString& line); // send input to server

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
