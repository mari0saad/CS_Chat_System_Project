#ifndef RENAMECOMMAND_H
#define RENAMECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class RenameCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};

#endif // RENAMECOMMAND_H
