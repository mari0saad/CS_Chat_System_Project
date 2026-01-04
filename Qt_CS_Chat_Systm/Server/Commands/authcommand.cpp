#include "authcommand.h"
#include "clientcontext.h"
#include <QString>
#include <QStringList>

AuthCommand::AuthCommand(const QString &rawLine)
{
    const QString args = rawLine.mid(QString("AUTH ").length());
    const QStringList parts = args.split(',');

    if (parts.size() == 2) {
        username = parts[0].trimmed();
        password = parts[1].trimmed();
    }
}

QString AuthCommand::execute(ClientContext &context)
{
    const auto result = authService.authenticate(username, password);
    QString errorCode ="";
    switch (result) {
    case AuthService::Result::Success:
        context.authenticated = true;
        context.username = username;
        errorCode = "OK Authenticated\n";
        break;
    case AuthService::Result::InvalidUsername:
        errorCode = "ERROR 101\n";
        break;
    case AuthService::Result::InvalidPassword:
        errorCode = "ERROR 102\n";
        break;
    default:
        errorCode = "ERROR 500\n"; // internal error
    }
    return errorCode;
}
