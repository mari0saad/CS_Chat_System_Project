#ifndef AUTHCOMMAND_H
#define AUTHCOMMAND_H

#include "authservice.h"
#include "iservercommand.h"
#include <QString>

struct ClientContext;

class AuthCommand : public IServerCommand
{
public:
    explicit AuthCommand(const QString& rawLine);
    QString execute(ClientContext& context) override;
private:
    QString username;
    QString password;
    AuthService authService;
};

#endif // AUTHCOMMAND_H
