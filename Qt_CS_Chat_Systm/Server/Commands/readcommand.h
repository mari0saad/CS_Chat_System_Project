#ifndef READCOMMAND_H
#define READCOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class ReadCommand : public IServerCommand
{
public:
    explicit ReadCommand(const QString& rawLine);
    QString execute(ClientContext& context) override;

private:
    QString filename;
    FileService fileService;
};

#endif // READCOMMAND_H
