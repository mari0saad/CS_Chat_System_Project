#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class ListCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};


#endif // LISTCOMMAND_H
