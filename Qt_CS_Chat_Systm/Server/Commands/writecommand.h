#ifndef WRITECOMMAND_H
#define WRITECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"


class WriteCommand : public IServerCommand
{
public:
    WriteCommand(const QString& rawLine);
    QString execute(ClientContext& context) override;
private:
    QString filename;
    QString data;
    FileService fileService;
};

#endif // WRITECOMMAND_H
