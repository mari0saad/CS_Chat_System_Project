#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class DeleteCommand : public IServerCommand
{
public:
    explicit DeleteCommand(const QString& rawLine);
    QString execute(ClientContext&) override;

private:
    QString filename;
    FileService fileService;
};

#endif // DELETECOMMAND_H
