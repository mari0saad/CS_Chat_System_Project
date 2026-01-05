#ifndef INFOCOMMAND_H
#define INFOCOMMAND_H

#include <iservercommand.h>
#include <fileservice.h>

class InfoCommand : public IServerCommand
{
public:
    explicit InfoCommand(const QString& rawLine);
    QString execute(ClientContext&) override;

private:
    QString filename;
    FileService fileService;
};

#endif // INFOCOMMAND_H
