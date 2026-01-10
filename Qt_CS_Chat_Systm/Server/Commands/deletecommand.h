#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class DeleteCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};


#endif // DELETECOMMAND_H
