#ifndef APPENDCOMMAND_H
#define APPENDCOMMAND_H

#include "fileservice.h"
#include "iservercommand.h"

class AppendCommand : public IServerCommand
{
public:
    QString execute(ClientContext* context, const ParsedCommand& cmd) override;
};

#endif // APPENDCOMMAND_H
