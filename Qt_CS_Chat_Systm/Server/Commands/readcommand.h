#ifndef READCOMMAND_H
#define READCOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class ReadCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};

#endif // READCOMMAND_H
