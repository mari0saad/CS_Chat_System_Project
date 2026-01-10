#ifndef WRITECOMMAND_H
#define WRITECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"


class WriteCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};


#endif // WRITECOMMAND_H
