#include "authcommand.h"
#include <QString>


QString AuthCommand::execute(ClientContext *context, const ParsedCommand &cmd)
{
    if (cmd.args.size() != 2)
        return "ERROR 400 AUTH requires username,password";

    const QString& username = cmd.args[0];
    const QString& password = cmd.args[1];

    AuthService::Result result =
            context->authService->authenticate(username, password);

    switch (result) {
    case AuthService::Result::Success:
        context->isAuthenticated = true;
        return "OK Authenticated";

    case AuthService::Result::InvalidUsername:
        return "ERROR 101 Invalid username";

    case AuthService::Result::InvalidPassword:
        return "ERROR 102 Invalid password";

    default:
        return "ERROR 500 Internal error";
    }
}
