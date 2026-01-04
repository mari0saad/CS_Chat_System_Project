#ifndef ISERVERCOMMAND_H
#define ISERVERCOMMAND_H

#include <QString>

struct ClientContext;

class IServerCommand
{
public:
    virtual ~IServerCommand() = default;
    virtual QString execute(ClientContext& context) = 0;
};

#endif // ISERVERCOMMAND_H
