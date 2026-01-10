#ifndef CREATECOMMAND_H
#define CREATECOMMAND_H

#include <iservercommand.h>


class CreateCommand : public IServerCommand {
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};

#endif // CREATECOMMAND_H
