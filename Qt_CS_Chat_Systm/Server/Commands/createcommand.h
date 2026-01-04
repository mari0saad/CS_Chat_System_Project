#ifndef CREATECOMMAND_H
#define CREATECOMMAND_H

#include <iservercommand.h>
#include <fileservice.h>

class CreateCommand : public IServerCommand
{
public:
    explicit CreateCommand(const QString& rawLine);

    QString execute(ClientContext& context) override;

private:
    QString filename;
    FileService fileService;
};

#endif // CREATECOMMAND_H
