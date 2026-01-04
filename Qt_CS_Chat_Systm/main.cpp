#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QTextStream>
#include <QSocketNotifier>

#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = QCoreApplication::arguments();
    QTextStream cin(stdin);
    QTextStream cout(stdout);

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
            /****************** Interactive Input ****************/
            QSocketNotifier notifier(fileno(stdin), QSocketNotifier::Read, &a);
            QObject::connect(&notifier, &QSocketNotifier::activated, [&]() {
            QString line = cin.readLine().trimmed();
            if (!line.isEmpty()) {
                client.sendLine(line);
            }
            cout << "> ";
            cout.flush();
            });

            cout << "> ";
            cout.flush();
            return a.exec();
        }
        else {
            qDebug() << "Please run with server or client";
            return 1;
        }
}

