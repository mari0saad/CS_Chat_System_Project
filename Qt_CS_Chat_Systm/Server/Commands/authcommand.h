#ifndef AUTHCOMMAND_H
#define AUTHCOMMAND_H

#include "authservice.h"
#include "iservercommand.h"
#include <QString>

class AuthCommand : public IServerCommand {
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};

#endif // AUTHCOMMAND_H
