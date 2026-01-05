#ifndef RENAMECOMMAND_H
#define RENAMECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class RenameCommand : public IServerCommand
{
public:
    explicit RenameCommand(const QString& rawLine);
    QString execute(ClientContext&) override;

private:
    QString oldName;
    QString newName;
    FileService fileService;
};
#endif // RENAMECOMMAND_H
