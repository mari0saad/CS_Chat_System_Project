#ifndef ISERVERCOMMAND_H
#define ISERVERCOMMAND_H

#include <QString>
#include "clientcontext.h"
#include "parsedcommand.h"

class IServerCommand
{
public:
    virtual ~IServerCommand() = default;
    virtual QString execute(ClientContext* context, const ParsedCommand& cmd) = 0;
};

#endif // ISERVERCOMMAND_H
