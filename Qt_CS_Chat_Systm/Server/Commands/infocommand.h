#ifndef INFOCOMMAND_H
#define INFOCOMMAND_H

#include <iservercommand.h>
#include <fileservice.h>

class InfoCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};


#endif // INFOCOMMAND_H
