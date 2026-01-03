#include <QCoreApplication>
#include <QStringList>
#include <QDebug>

#include "Server/server.h"
#include "Client/client.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = QCoreApplication::arguments();

        if (args.contains("server")) {
            qDebug() << "Starting server...";
            Server server;
            server.start(5000); // Local port
            return a.exec();
        }
        else if (args.contains("client")) {
            qDebug() << "Starting client...";
            Client client;
            client.connectToServer("127.0.0.1", 5000);
            return a.exec();
        }
        else {
            qDebug() << "Please run with server or client";
            return 1;
        }
}
